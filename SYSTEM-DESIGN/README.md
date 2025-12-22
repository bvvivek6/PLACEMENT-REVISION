# System Design Interview Guide

Welcome to the System Design Interview Guide. This repository is designed to take you from basic concepts to advanced High-Level Design (HLD) case studies, specifically tailored for technical interviews.

## Structure

The repository is organized into the following sections:

### [01. Fundamentals](./01-fundamentals/)

Core concepts that form the building blocks of any distributed system.

- [Scalability Basics](./01-fundamentals/scalability-basics.md) (Vertical vs Horizontal, Latency vs Throughput)
- [CAP Theorem](./01-fundamentals/cap-theorem.md)
- [Database Scaling](./01-fundamentals/database-scaling.md) (Sharding, Replication, Consistent Hashing)
- [Microservices Architecture](./01-fundamentals/microservices.md)
- [API Design](./01-fundamentals/api-design.md) (REST, GraphQL, gRPC)
- [Networking Basics](./01-fundamentals/networking-basics.md) (TCP/UDP, HTTP Protocols)
- [Security](./01-fundamentals/security.md) (Encryption, Hashing, OWASP, CORS)

### [02. Components](./02-components/)

Deep dives into specific infrastructure components.

- [Load Balancers](./02-components/load-balancers.md)
- [Caching Strategies](./02-components/caching.md)
- [Message Queues](./02-components/message-queues.md) (Kafka vs RabbitMQ)
- [Databases](./02-components/databases-sql-vs-nosql.md) (SQL vs NoSQL)
- CDN & Blob Storage

### [03. High-Level Design (HLD) Case Studies](./03-hld-case-studies/)

Real-world system design problems often asked in interviews.

- Design a URL Shortener (TinyURL)
- Design a Social Media Feed (Instagram/Twitter)
- Design a Chat System (WhatsApp/Messenger)
- Design a Video Streaming Service (YouTube/Netflix)
- Design a Rate Limiter
- Design a Web Crawler

### [04. Interview Guide](./04-interview-guide/)

A framework for approaching system design questions during the actual interview.

- The 4-Step Framework
- Requirements Gathering
- Back-of-the-envelope Calculations

## How to use this repo

Start with the **Interview Guide** to understand the structure of a system design interview. Then, review **Fundamentals** and **Components** to ensure you have the necessary tools. Finally, practice with the **HLD Case Studies**.
