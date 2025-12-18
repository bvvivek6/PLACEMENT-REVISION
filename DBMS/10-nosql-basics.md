# NoSQL Basics

**NoSQL (Not Only SQL)** databases are designed for distributed data stores where very large scale of data storage needs are required. They are used for Big Data and real-time web applications.

## CAP Theorem

The CAP theorem states that a distributed computer system can only provide two of the following three guarantees:

1.  **Consistency (C):** Every read receives the most recent write or an error. All nodes see the same data at the same time.
2.  **Availability (A):** Every request receives a (non-error) response, without the guarantee that it contains the most recent write.
3.  **Partition Tolerance (P):** The system continues to operate despite an arbitrary number of messages being dropped or delayed by the network between nodes.

- **CA:** RDBMS (MySQL, PostgreSQL) - Hard to achieve in distributed systems.
- **CP:** MongoDB, HBase, Redis - Consistent and Partition Tolerant.
- **AP:** Cassandra, DynamoDB - Available and Partition Tolerant.

## BASE Properties

NoSQL databases often follow the BASE model instead of ACID.

- **Basically Available:** The system guarantees availability.
- **Soft state:** The state of the system may change over time, even without input.
- **Eventual consistency:** The system will eventually become consistent once it stops receiving input.

## Types of NoSQL Databases

### 1. Key-Value Stores

- Stores data as a collection of key-value pairs.
- **Use Case:** Caching, Session management.
- **Examples:** Redis, DynamoDB, Riak.

### 2. Document Stores

- Stores data in documents (JSON, BSON, XML).
- **Use Case:** Content management systems, catalogs.
- **Examples:** MongoDB, CouchDB.

### 3. Column-Oriented Stores

- Stores data in columns rather than rows.
- **Use Case:** Analytics, Data Warehousing.
- **Examples:** Cassandra, HBase.

### 4. Graph Databases

- Stores data in nodes and edges.
- **Use Case:** Social networks, Recommendation engines.
- **Examples:** Neo4j, Amazon Neptune.
