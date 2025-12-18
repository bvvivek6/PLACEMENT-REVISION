# SQL Advanced

## Window Functions

Perform calculations across a set of table rows that are somehow related to the current row. Unlike `GROUP BY`, window functions do not collapse rows.

### Syntax

```sql
SELECT column_name,
       FUNCTION(column_name) OVER (PARTITION BY column_name ORDER BY column_name)
FROM table_name;
```

### Common Window Functions

- `ROW_NUMBER()`: Assigns a unique number to each row.
- `RANK()`: Assigns a rank, with gaps for ties (e.g., 1, 2, 2, 4).
- `DENSE_RANK()`: Assigns a rank, without gaps for ties (e.g., 1, 2, 2, 3).
- `NTILE(n)`: Divides rows into `n` buckets.
- `LEAD()`: Accesses data from the next row.
- `LAG()`: Accesses data from the previous row.

```sql
-- Rank employees by salary within each department
SELECT Name, Department, Salary,
       RANK() OVER (PARTITION BY Department ORDER BY Salary DESC) as Rank
FROM Employees;
```

## Common Table Expressions (CTEs)

A temporary result set that you can reference within a `SELECT`, `INSERT`, `UPDATE`, or `DELETE` statement.

```sql
WITH HighSalaryEmployees AS (
    SELECT * FROM Employees WHERE Salary > 50000
)
SELECT * FROM HighSalaryEmployees WHERE Department = 'IT';
```

## Views

A virtual table based on the result-set of an SQL statement.

- **Advantages:** Security (hide columns), Simplicity (complex queries become simple selects).

```sql
CREATE VIEW IT_Employees AS
SELECT Name, Email FROM Employees WHERE Department = 'IT';

-- Usage
SELECT * FROM IT_Employees;
```

## Stored Procedures

A prepared SQL code that you can save, so the code can be reused over and over again.

```sql
CREATE PROCEDURE GetEmployeeByDept (IN deptName VARCHAR(50))
BEGIN
    SELECT * FROM Employees WHERE Department = deptName;
END;

-- Usage
CALL GetEmployeeByDept('HR');
```

## Triggers

A stored procedure that automatically runs when an event occurs in the database server (INSERT, UPDATE, DELETE).

```sql
CREATE TRIGGER BeforeInsertStudent
BEFORE INSERT ON Students
FOR EACH ROW
BEGIN
    IF NEW.Age < 18 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Age must be at least 18';
    END IF;
END;
```
