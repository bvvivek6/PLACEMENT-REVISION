# Databases: SQL vs. NoSQL

Choosing the right database is one of the most important design decisions.

## SQL (Relational Databases)

- **Structure:** Tables with fixed rows and columns (Schema).
- **Properties:** ACID (Atomicity, Consistency, Isolation, Durability).
- **Scaling:** Vertical (mostly). Horizontal is hard (requires manual sharding).
- **Querying:** SQL (JOINs are powerful).
- **Examples:** MySQL, PostgreSQL, Oracle, SQL Server.
- **Best For:** Financial systems, structured data, complex relationships.

### Example: SQL Schema

```sql
CREATE TABLE Users (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100)
);

CREATE TABLE Orders (
    id INT PRIMARY KEY,
    user_id INT,
    amount DECIMAL(10, 2),
    FOREIGN KEY (user_id) REFERENCES Users(id)
);
```

## NoSQL (Non-Relational Databases)

- **Structure:** Flexible schema.
- **Properties:** BASE (Basically Available, Soft state, Eventual consistency).
- **Scaling:** Horizontal (built-in sharding).
- **Best For:** Big data, real-time apps, unstructured data.

### Types of NoSQL

#### 1. Key-Value Stores

Data is stored as a hash map.

- **Examples:** Redis, Memcached, DynamoDB.
- **Use Case:** Caching, Sessions, Shopping Carts.

```json
"user:123": { "name": "Alice", "role": "admin" }
```

#### 2. Document Stores

Data is stored as JSON/XML documents.

- **Examples:** MongoDB, Couchbase.
- **Use Case:** CMS, Catalogs, User Profiles.

```json
{
  "_id": "123",
  "name": "Alice",
  "orders": [
    { "id": "A1", "amount": 50 },
    { "id": "A2", "amount": 100 }
  ]
}
```

#### 3. Column-Oriented (Wide-Column)

Data is stored in columns instead of rows. Optimized for writing and reading huge datasets.

- **Examples:** Cassandra, HBase.
- **Use Case:** Analytics, Time-series data, Logs.

#### 4. Graph Databases

Stores nodes and edges.

- **Examples:** Neo4j.
- **Use Case:** Social Networks (Friends), Recommendation Engines.

```cypher
(Alice)-[:FRIEND]->(Bob)
```

## Comparison Matrix

| Feature          | SQL                   | NoSQL                      |
| :--------------- | :-------------------- | :------------------------- |
| **Schema**       | Rigid (Fixed columns) | Flexible (JSON, Key-Value) |
| **Relations**    | JOINs                 | Denormalized (Embedded)    |
| **Consistency**  | Strong (ACID)         | Eventual (BASE)            |
| **Scaling**      | Vertical (Scale Up)   | Horizontal (Scale Out)     |
| **Transactions** | Supported             | Limited / Not Supported    |

## When to choose what?

```mermaid
graph TD
    Start{Structured Data?}
    Start -- Yes --> ACID{Need ACID?}
    ACID -- Yes --> SQL[SQL (PostgreSQL/MySQL)]
    ACID -- No --> Scale{Need Massive Scale?}

    Start -- No --> Type{Data Type?}
    Type -- JSON Documents --> Mongo[MongoDB]
    Type -- Key-Value --> Redis[Redis/DynamoDB]
    Type -- Graph/Relations --> Neo4j[Neo4j]
    Type -- Time Series/Logs --> Cassandra[Cassandra]

    Scale -- Yes --> Cassandra
    Scale -- No --> Mongo
```
