# API Design

Designing clean, efficient, and scalable APIs is critical for system communication. This guide covers key protocols, patterns, and best practices with examples.

## Protocols

### REST (Representational State Transfer)

REST is an architectural style that uses standard HTTP methods to interact with resources.

- **Resource-based:** URLs represent resources (nouns), not actions (verbs).
- **Stateless:** Server doesn't store client context between requests. Each request must contain all necessary information.
- **Pros:** Simple, cacheable, widely supported, decoupled client/server.
- **Cons:** Over-fetching (getting more data than needed) or Under-fetching (needing multiple requests).

#### Example: RESTful User Resource

**Request:** `GET /users/123`

```http
GET /users/123 HTTP/1.1
Host: api.example.com
Accept: application/json
```

**Response:** `200 OK`

```json
{
  "id": "123",
  "name": "Alice Smith",
  "email": "alice@example.com",
  "role": "admin",
  "links": {
    "orders": "/users/123/orders"
  }
}
```

#### REST Maturity Model (Richardson Maturity Model)

1.  **Level 0:** The Swamp of POX (Plain Old XML) - Single URI, single method (usually POST).
2.  **Level 1:** Resources - Multiple URIs, single method.
3.  **Level 2:** HTTP Verbs - Standard methods (GET, POST, PUT, DELETE).
4.  **Level 3:** HATEOAS (Hypermedia As The Engine Of Application State) - API responses contain links to related actions.

### GraphQL

GraphQL is a query language for APIs that allows clients to request exactly the data they need.

- **Single Endpoint:** All requests go to `/graphql`.
- **Flexible:** Solves over-fetching and under-fetching.
- **Strongly Typed:** Schema defines the API capabilities.
- **Cons:** Complex caching (since everything is POST), N+1 query problem (requires DataLoaders).

#### Example: GraphQL Query

**Schema Definition (SDL):**

```graphql
type User {
  id: ID!
  name: String!
  email: String
  orders: [Order]
}

type Order {
  id: ID!
  total: Float
}

type Query {
  user(id: ID!): User
}
```

**Client Query:**

```graphql
query {
  user(id: "123") {
    name
    orders {
      total
    }
  }
}
```

**Response:**

```json
{
  "data": {
    "user": {
      "name": "Alice Smith",
      "orders": [{ "total": 99.99 }, { "total": 45.5 }]
    }
  }
}
```

### gRPC (Google Remote Procedure Call)

gRPC is a high-performance RPC framework that uses **Protocol Buffers** (Protobuf) for serialization.

- **Binary Protocol:** Uses HTTP/2 for transport and binary data (faster, smaller than JSON).
- **Contract-First:** Defined via `.proto` files.
- **Pros:** High performance, supports bi-directional streaming, language agnostic, auto-generated code.
- **Cons:** Browser support is limited (requires gRPC-Web proxy), harder to debug (binary data).

#### Example: Protobuf Definition

```protobuf
syntax = "proto3";

service UserService {
  rpc GetUser (UserRequest) returns (UserResponse);
}

message UserRequest {
  string id = 1;
}

message UserResponse {
  string id = 1;
  string name = 2;
  string email = 3;
}
```

## Comparison Diagram

```mermaid
graph TD
    subgraph REST
    C1[Client] -->|GET /users/1| S1[Server]
    S1 -->|JSON Full Object| C1
    end

    subgraph GraphQL
    C2[Client] -->|POST /graphql { user { name } }| S2[Server]
    S2 -->|JSON { user: { name } }| C2
    end

    subgraph gRPC
    C3[Client] -->|Proto Request (Binary)| S3[Server]
    S3 -->|Proto Response (Binary)| C3
    end
```

## Best Practices

### Idempotency

An operation is idempotent if applying it multiple times has the same result as applying it once. This is crucial for payment processing and unreliable networks.

- **Safe Methods:** `GET`, `HEAD`, `OPTIONS` (Read-only).
- **Idempotent Methods:** `PUT`, `DELETE` (Repeating the request results in the same state).
- **Non-Idempotent:** `POST` (Usually creates a new resource).

#### Implementing Idempotency for POST

Use an `Idempotency-Key` header.

```python
# Python / Flask Pseudo-code
@app.route('/charge', methods=['POST'])
def charge_customer():
    key = request.headers.get('Idempotency-Key')
    if not key:
        return error("Missing Idempotency-Key"), 400

    # Check if we already processed this key
    cached_response = redis.get(key)
    if cached_response:
        return cached_response

    # Process payment
    result = payment_gateway.charge(...)

    # Save response
    redis.set(key, result, expire=86400)

    return result
```

### Pagination

Never return all records. Large datasets crash servers and clients.

#### 1. Offset-based Pagination

Simple but slow for large datasets (database must scan and skip rows).

- **API:** `GET /items?limit=10&offset=20`
- **SQL:** `SELECT * FROM items LIMIT 10 OFFSET 20;`

#### 2. Cursor-based Pagination (Keyset Pagination)

More efficient and handles real-time data better (no skipped rows if new items are added).

- **API:** `GET /items?limit=10&after=cursor_id_xyz`
- **SQL:** `SELECT * FROM items WHERE id > 'cursor_id_xyz' LIMIT 10;`

### Status Codes

Use standard HTTP status codes to communicate outcomes.

| Range   | Category     | Examples                                                                                                                                                   |
| :------ | :----------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **2xx** | Success      | `200 OK` (Standard), `201 Created` (Resource created), `204 No Content` (Delete success)                                                                   |
| **3xx** | Redirection  | `301 Moved Permanently` (SEO friendly), `304 Not Modified` (Caching)                                                                                       |
| **4xx** | Client Error | `400 Bad Request` (Validation), `401 Unauthorized` (Auth missing), `403 Forbidden` (Auth failed), `404 Not Found`, `429 Too Many Requests` (Rate limiting) |
| **5xx** | Server Error | `500 Internal Server Error` (Bug), `502 Bad Gateway` (Upstream issue), `503 Service Unavailable` (Overload)                                                |

### API Versioning

Changes happen. Version your API to avoid breaking clients.

1.  **URI Versioning:** `GET /v1/users` (Most common, easy to cache).
2.  **Header Versioning:** `Accept: application/vnd.myapi.v1+json` (Cleaner URLs, harder to test in browser).
3.  **Query Parameter:** `GET /users?version=1` (Simple, but can be messy).
