# Load Balancers

A Load Balancer (LB) distributes incoming network traffic across a group of backend servers. It ensures no single server bears too much load.

## Where to place a Load Balancer?

1.  Between User and Web Server.
2.  Between Web Server and Internal Platform Layer (App Server).
3.  Between Internal Platform Layer and Database.

```mermaid
graph LR
    User --> LB1[Public LB]
    LB1 --> Web1[Web Server 1]
    LB1 --> Web2[Web Server 2]
    Web1 --> LB2[Internal LB]
    Web2 --> LB2
    LB2 --> App1[App Server 1]
    LB2 --> App2[App Server 2]
    App1 --> DB[(Database)]
    App2 --> DB
```

## Algorithms

### 1. Round Robin

Requests are distributed sequentially.

- **Pros:** Simple.
- **Cons:** Doesn't account for server load or capacity.

### 2. Least Connections

Sends requests to the server with the fewest active connections.

- **Pros:** Good for sessions of varying length.

### 3. IP Hash

Uses the client's IP address to determine which server receives the request.

- **Pros:** Ensures a user is always connected to the same server (Sticky Sessions).

## Types of Load Balancers

### Layer 4 (Transport Layer)

- Makes decisions based on IP address and Port (TCP/UDP).
- Faster, less context-aware.
- **Example:** HAProxy (TCP mode), AWS Network Load Balancer (NLB).

### Layer 7 (Application Layer)

- Makes decisions based on content (URL, Cookies, Headers).
- Can route `/video` to video servers and `/chat` to chat servers.
- **Example:** Nginx, AWS Application Load Balancer (ALB).

#### Nginx Configuration Example (L7)

```nginx
http {
    upstream backend_servers {
        server backend1.example.com;
        server backend2.example.com;
        server backend3.example.com;
    }

    server {
        listen 80;
        location / {
            proxy_pass http://backend_servers;
        }

        # Route /api to a specific group
        location /api {
            proxy_pass http://api_servers;
        }
    }
}
```

## Health Checks

LBs regularly check if servers are healthy. If a server fails a health check, the LB stops sending traffic to it until it recovers.

- **Active Health Check:** LB pings the server (e.g., `GET /health`).
- **Passive Health Check:** LB observes real traffic. If 500 errors occur, it marks the server as unhealthy.

```mermaid
sequenceDiagram
    participant LB
    participant Server1
    participant Server2

    loop Every 5 seconds
        LB->>Server1: GET /health
        Server1-->>LB: 200 OK
        LB->>Server2: GET /health
        Server2-->>LB: 500 Error
        Note over LB: Mark Server2 as Unhealthy
    end
```
