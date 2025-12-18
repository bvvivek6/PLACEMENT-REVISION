# Introduction to DBMS

## What is DBMS?

A **Database Management System (DBMS)** is software that interacts with end-users, applications, and the database itself to capture and analyze the data. It provides an interface to perform various operations like creating, storing, updating, and deleting data in the database.

**Examples:** MySQL, PostgreSQL, Oracle, SQL Server, MongoDB.

## File System vs DBMS

| Feature              | File System                                         | DBMS                                      |
| :------------------- | :-------------------------------------------------- | :---------------------------------------- |
| **Data Redundancy**  | High (Data duplication is common)                   | Low (Normalization reduces redundancy)    |
| **Data Consistency** | Low (Changes in one file may not reflect in others) | High (Changes are updated globally)       |
| **Data Access**      | Difficult (Need specific programs)                  | Easy (Using query languages like SQL)     |
| **Security**         | Low                                                 | High (User roles and permissions)         |
| **Concurrency**      | Poor                                                | Good (Handles multiple users efficiently) |
| **Crash Recovery**   | Poor                                                | Good (Backup and recovery mechanisms)     |

## RDBMS vs NoSQL

| Feature            | RDBMS (Relational)              | NoSQL (Non-Relational)                                      |
| :----------------- | :------------------------------ | :---------------------------------------------------------- |
| **Structure**      | Structured data (Tables)        | Unstructured/Semi-structured (Documents, Key-Value, Graphs) |
| **Schema**         | Fixed Schema                    | Dynamic Schema                                              |
| **Scalability**    | Vertical Scaling (Scale Up)     | Horizontal Scaling (Scale Out)                              |
| **Query Language** | SQL (Structured Query Language) | UnQL (Unstructured Query Language)                          |
| **Examples**       | MySQL, PostgreSQL, Oracle       | MongoDB, Cassandra, Redis                                   |

## ACID Properties

ACID properties ensure that database transactions are processed reliably.

1.  **Atomicity:**

    - A transaction is treated as a single unit of work. Either all its operations are executed, or none are.
    - _Example:_ In a bank transfer, money is deducted from A and added to B. If one fails, the entire transaction rolls back.

2.  **Consistency:**

    - The database must remain in a consistent state before and after the transaction.
    - _Example:_ The total money in the bank should remain the same before and after the transfer.

3.  **Isolation:**

    - Multiple transactions occurring at the same time should not interfere with each other.
    - _Example:_ If two people withdraw money from the same account simultaneously, the transactions should be processed sequentially or with proper locking.

4.  **Durability:**
    - Once a transaction is committed, the changes are permanent, even in the case of a system failure.
    - _Example:_ If the system crashes after a successful transfer, the money should still be transferred upon restart.
