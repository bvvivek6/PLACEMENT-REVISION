# Transactions and Concurrency Control

## Transaction States

A transaction goes through the following states:

1.  **Active:** The initial state. The transaction stays in this state while it is executing.
2.  **Partially Committed:** After the final statement has been executed.
3.  **Committed:** After successful completion.
4.  **Failed:** When normal execution can no longer proceed.
5.  **Aborted:** After the transaction has been rolled back and the database restored to its state prior to the start of the transaction.

## Schedules and Serializability

- **Schedule:** A sequence of instructions that specify the chronological order in which instructions of concurrent transactions are executed.
- **Serial Schedule:** Transactions are executed one after another.
- **Concurrent Schedule:** Transactions are interleaved.
- **Serializability:** A concurrent schedule is serializable if it is equivalent to a serial schedule.
  - **Conflict Serializability:** Based on conflicting operations (Read-Write, Write-Read, Write-Write on the same data item).
  - **View Serializability:** Based on the final view of the data.

## Concurrency Control Protocols

### 1. Lock-Based Protocols

- **Shared Lock (S):** Read-only lock. Multiple transactions can hold S lock.
- **Exclusive Lock (X):** Read-Write lock. Only one transaction can hold X lock.
- **Two-Phase Locking (2PL):**
  - **Growing Phase:** Transaction acquires locks but cannot release any.
  - **Shrinking Phase:** Transaction releases locks but cannot acquire any.
  - _Ensures Serializability._

### 2. Timestamp-Based Protocols

- Assigns a unique timestamp to each transaction.
- Transactions are executed in timestamp order.
- _Ensures Serializability and Freedom from Deadlock._

## Deadlocks

A situation where two or more transactions are waiting indefinitely for one another to give up locks.

- **Deadlock Prevention:** Wait-Die or Wound-Wait schemes.
- **Deadlock Detection:** Wait-for graph.
- **Deadlock Recovery:** Select a victim and rollback.

## Isolation Levels

Defines the degree to which a transaction must be isolated from the data modifications made by other transactions.

1.  **Read Uncommitted:** Lowest level. Allows Dirty Reads.
2.  **Read Committed:** Prevents Dirty Reads.
3.  **Repeatable Read:** Prevents Dirty Reads and Non-Repeatable Reads.
4.  **Serializable:** Highest level. Prevents Dirty Reads, Non-Repeatable Reads, and Phantom Reads.

### Read Phenomena

- **Dirty Read:** Reading uncommitted data.
- **Non-Repeatable Read:** Reading the same row twice gets different data (because someone updated it).
- **Phantom Read:** Reading the same range twice gets different number of rows (because someone inserted/deleted rows).
