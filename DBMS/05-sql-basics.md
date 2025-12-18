# SQL Basics

**SQL (Structured Query Language)** is the standard language for dealing with Relational Databases.

## SQL Command Categories

### 1. DDL (Data Definition Language)

Defines the structure of the database.

- `CREATE`: Creates a new table, database, index, etc.
- `ALTER`: Modifies an existing database object.
- `DROP`: Deletes an entire table or database.
- `TRUNCATE`: Removes all records from a table but keeps the structure.
- `RENAME`: Renames an object.

### 2. DML (Data Manipulation Language)

Manipulates the data within the database.

- `INSERT`: Inserts new data.
- `UPDATE`: Updates existing data.
- `DELETE`: Deletes specific records.
- `SELECT`: Retrieves data (Sometimes categorized as DQL - Data Query Language).

### 3. DCL (Data Control Language)

Controls access to the data.

- `GRANT`: Gives user's access privileges.
- `REVOKE`: Withdraws access privileges.

### 4. TCL (Transaction Control Language)

Manages transactions.

- `COMMIT`: Saves the work done.
- `ROLLBACK`: Restores the database to the original state since the last COMMIT.
- `SAVEPOINT`: Sets a point in a transaction to which you can later rollback.

## Basic SQL Queries

### CREATE Table

```sql
CREATE TABLE Students (
    ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT,
    Department VARCHAR(50)
);
```

### INSERT Data

```sql
INSERT INTO Students (ID, Name, Age, Department)
VALUES (1, 'Alice', 20, 'CS'),
       (2, 'Bob', 22, 'IT');
```

### SELECT Data

```sql
-- Select all columns
SELECT * FROM Students;

-- Select specific columns
SELECT Name, Age FROM Students;

-- Select distinct values
SELECT DISTINCT Department FROM Students;
```

### WHERE Clause (Filtering)

```sql
SELECT * FROM Students WHERE Age > 21;
SELECT * FROM Students WHERE Department = 'CS' AND Age < 25;
```

### ORDER BY (Sorting)

```sql
SELECT * FROM Students ORDER BY Age ASC; -- Ascending
SELECT * FROM Students ORDER BY Name DESC; -- Descending
```

### UPDATE Data

```sql
UPDATE Students SET Age = 21 WHERE ID = 1;
```

### DELETE Data

```sql
DELETE FROM Students WHERE ID = 2;
```
