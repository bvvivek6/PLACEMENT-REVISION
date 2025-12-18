# SQL Intermediate

## Joins

Joins are used to combine rows from two or more tables based on a related column between them.

### 1. INNER JOIN

Returns records that have matching values in both tables.

```sql
SELECT Students.Name, Courses.CourseName
FROM Students
INNER JOIN Courses ON Students.CourseID = Courses.ID;
```

### 2. LEFT JOIN (LEFT OUTER JOIN)

Returns all records from the left table, and the matched records from the right table.

```sql
SELECT Students.Name, Courses.CourseName
FROM Students
LEFT JOIN Courses ON Students.CourseID = Courses.ID;
```

### 3. RIGHT JOIN (RIGHT OUTER JOIN)

Returns all records from the right table, and the matched records from the left table.

```sql
SELECT Students.Name, Courses.CourseName
FROM Students
RIGHT JOIN Courses ON Students.CourseID = Courses.ID;
```

### 4. FULL JOIN (FULL OUTER JOIN)

Returns all records when there is a match in either left or right table.

```sql
SELECT Students.Name, Courses.CourseName
FROM Students
FULL OUTER JOIN Courses ON Students.CourseID = Courses.ID;
```

### 5. CROSS JOIN

Returns the Cartesian product of the two tables.

```sql
SELECT Students.Name, Courses.CourseName
FROM Students
CROSS JOIN Courses;
```

### 6. SELF JOIN

A regular join, but the table is joined with itself.

```sql
SELECT A.Name AS Employee, B.Name AS Manager
FROM Employees A, Employees B
WHERE A.ManagerID = B.ID;
```

## Aggregation Functions

Perform a calculation on a set of values and return a single value.

- `COUNT()`: Returns the number of rows.
- `SUM()`: Returns the total sum of a numeric column.
- `AVG()`: Returns the average value.
- `MIN()`: Returns the smallest value.
- `MAX()`: Returns the largest value.

```sql
SELECT COUNT(*) FROM Students;
SELECT AVG(Age) FROM Students;
SELECT MAX(Salary) FROM Employees;
```

## GROUP BY and HAVING

- `GROUP BY`: Groups rows that have the same values into summary rows.
- `HAVING`: Used instead of `WHERE` with aggregate functions.

```sql
-- Count number of students in each department
SELECT Department, COUNT(*)
FROM Students
GROUP BY Department;

-- Show departments with more than 5 students
SELECT Department, COUNT(*)
FROM Students
GROUP BY Department
HAVING COUNT(*) > 5;
```

## Subqueries (Nested Queries)

A query within another query.

### Scalar Subquery

Returns a single value.

```sql
SELECT * FROM Students
WHERE Age > (SELECT AVG(Age) FROM Students);
```

### Multi-row Subquery

Returns multiple rows. Used with `IN`, `ANY`, `ALL`.

```sql
SELECT * FROM Students
WHERE Department IN (SELECT Department FROM Departments WHERE Location = 'New York');
```

### Correlated Subquery

A subquery that uses values from the outer query.

```sql
SELECT Name, Salary
FROM Employees E1
WHERE Salary > (SELECT AVG(Salary) FROM Employees E2 WHERE E1.Department = E2.Department);
```
