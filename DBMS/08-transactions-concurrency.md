# Transactions and Concurrency Control

## Transaction States

A transaction goes through the following states:

1.  **Active:** The initial state. The transaction stays in this state while it is executing.
2.  **Partially Committed:** After the final statement has been executed.
3.  **Committed:** After successful completion.
4.  **Failed:** When normal execution can no longer proceed.
5.  **Aborted:** After the transaction has been rolled back and the database restored to its state prior to the start of the transaction.

## Basic Transaction Example (SQL)
Here is how you manage transactions using SQL commands.

```sql
-- Start a new transaction
START TRANSACTION; -- or BEGIN;

-- Deduct $100 from Account A
UPDATE Accounts SET Balance = Balance - 100 WHERE AccountID = 'A';

-- Add $100 to Account B
UPDATE Accounts SET Balance = Balance + 100 WHERE AccountID = 'B';

-- If everything is fine, save changes
COMMIT;

-- If something goes wrong (e.g., insufficient funds), undo changes
ROLLBACK;
```

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

### 1. Read Uncommitted
*   **Behavior:** Transactions can see uncommitted changes made by other transactions.
*   **Problem:** Dirty Reads.

**Example (Dirty Read):**
*   **Transaction A:** Updates a row but hasn't committed yet.
*   **Transaction B:** Reads that row (sees the new value).
*   **Transaction A:** Rolls back.
*   **Result:** Transaction B has "dirty" data that never officially existed.

```sql
-- Session 1
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
START TRANSACTION;
UPDATE Products SET Price = 200 WHERE ID = 1; -- Original was 100
-- (Not committed yet)

-- Session 2
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
SELECT Price FROM Products WHERE ID = 1; -- Returns 200 (Dirty Read)

-- Session 1
ROLLBACK; -- Price goes back to 100
```

### 2. Read Committed
*   **Behavior:** A transaction only sees changes that have been committed.
*   **Problem:** Non-Repeatable Reads.

**Example (Non-Repeatable Read):**
*   **Transaction A:** Reads a row.
*   **Transaction B:** Updates that row and commits.
*   **Transaction A:** Reads the row again and gets a different value.

```sql
-- Session 1
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
START TRANSACTION;
SELECT Price FROM Products WHERE ID = 1; -- Returns 100

-- Session 2
UPDATE Products SET Price = 200 WHERE ID = 1;
COMMIT;

-- Session 1
SELECT Price FROM Products WHERE ID = 1; -- Returns 200 (Different from first read)
COMMIT;
```

### 3. Repeatable Read
*   **Behavior:** Ensures that if a transaction reads a row, it will see the same data if it reads it again.
*   **Problem:** Phantom Reads.

**Example (Phantom Read):**
*   **Transaction A:** Selects all products with Price > 100 (Returns 5 rows).
*   **Transaction B:** Inserts a new product with Price = 150 and commits.
*   **Transaction A:** Selects all products with Price > 100 again (Returns 6 rows).

```sql
-- Session 1
SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
START TRANSACTION;
SELECT * FROM Products WHERE Price > 100; -- Returns 5 rows

-- Session 2
INSERT INTO Products (Name, Price) VALUES ('New Item', 150);
COMMIT;

-- Session 1
SELECT * FROM Products WHERE Price > 100; -- Returns 6 rows (Phantom Read)
-- Note: Some databases like MySQL (InnoDB) prevent Phantom Reads in Repeatable Read using Gap Locks.
COMMIT;
```

### 4. Serializable
*   **Behavior:** The strictest level. It emulates serial execution, as if transactions were executed one after another.
*   **Trade-off:** Lowest concurrency, highest consistency.

```sql
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
-- Locks the range of rows, preventing other transactions from inserting/updating in that range.
```

### Read Phenomena Summary
*   **Dirty Read:** Reading uncommitted data.
*   **Non-Repeatable Read:** Reading the same row twice gets different data (because someone updated it).
*   **Phantom Read:** Reading the same range twice gets different number of rows (because someone inserted/deleted rows).
