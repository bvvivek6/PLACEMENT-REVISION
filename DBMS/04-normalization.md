# Normalization

**Normalization** is the process of organizing data in a database to reduce redundancy (duplicate data) and improve data integrity. It involves dividing large tables into smaller, related tables and linking them using relationships.

## Why do we need Normalization? (Database Anomalies)

Without normalization, we face three types of anomalies. Let's consider a **Student_Course** table:

| StudentID | Name  | CourseID | CourseName | Professor | ProfessorPhone |
| :-------- | :---- | :------- | :--------- | :-------- | :------------- |
| 1         | Alice | C101     | Math       | Dr. Smith | 123-4567       |
| 1         | Alice | C102     | Physics    | Dr. Jones | 987-6543       |
| 2         | Bob   | C101     | Math       | Dr. Smith | 123-4567       |

1.  **Update Anomaly:**
    - If Dr. Smith changes his phone number, we must update it in _every_ row where he appears (Rows 1 and 3). If we miss one, data becomes inconsistent.
2.  **Insertion Anomaly:**
    - We cannot add a new course "Chemistry" unless a student enrolls in it, because `StudentID` is part of the Primary Key. We can't have a course without a student.
3.  **Deletion Anomaly:**
    - If Bob drops Math (Row 3), and he was the only student in Math, we lose all information about the Math course and Dr. Smith.

---

## Normal Forms

### 1. First Normal Form (1NF)

**Rule:**

- Each column must contain only **atomic (indivisible)** values.
- No repeating groups or arrays.
- Each record must be unique.

**Problem (Not in 1NF):**
A student has multiple phone numbers stored in one cell.

| ID  | Name  | Phone            |
| :-- | :---- | :--------------- |
| 1   | Alice | 123-456, 999-000 |
| 2   | Bob   | 555-123          |

**Solution (Converted to 1NF):**
Split the values into separate rows.

| ID  | Name  | Phone   |
| :-- | :---- | :------ |
| 1   | Alice | 123-456 |
| 1   | Alice | 999-000 |
| 2   | Bob   | 555-123 |

---

### 2. Second Normal Form (2NF)

**Rule:**

- Must be in **1NF**.
- **No Partial Dependency:** All non-key attributes must depend on the _entire_ Primary Key, not just a part of it.
- _Note:_ This applies mainly when the Primary Key is a **Composite Key** (made of multiple columns).

**Problem (Not in 2NF):**
Table: **Grades**
Primary Key: `(StudentID, CourseID)`

| StudentID | CourseID | Grade | CourseName |
| :-------- | :------- | :---- | :--------- |
| 1         | C101     | A     | Math       |
| 2         | C101     | B     | Math       |

- `Grade` depends on both `StudentID` and `CourseID` (Correct).
- `CourseName` depends _only_ on `CourseID`. It does not depend on `StudentID`. This is a **Partial Dependency**.

**Solution (Converted to 2NF):**
Split into two tables.

**Table 1: Grades**
| StudentID | CourseID | Grade |
| :--- | :--- | :--- |
| 1 | C101 | A |
| 2 | C101 | B |

**Table 2: Courses**
| CourseID | CourseName |
| :--- | :--- |
| C101 | Math |

---

### 3. Third Normal Form (3NF)

**Rule:**

- Must be in **2NF**.
- **No Transitive Dependency:** A non-key attribute must not depend on another non-key attribute.
- _Ideally: "Every non-key attribute must depend on the Key, the whole Key, and nothing but the Key."_

**Problem (Not in 3NF):**
Table: **Students**
Primary Key: `StudentID`

| StudentID | Name  | ZipCode | City        |
| :-------- | :---- | :------ | :---------- |
| 1         | Alice | 10001   | New York    |
| 2         | Bob   | 90001   | Los Angeles |

- `City` depends on `ZipCode`.
- `ZipCode` depends on `StudentID`.
- Therefore, `StudentID` -> `ZipCode` -> `City`. This is a **Transitive Dependency**.

**Solution (Converted to 3NF):**
Move the transitive dependency to a new table.

**Table 1: Students**
| StudentID | Name | ZipCode |
| :--- | :--- | :--- |
| 1 | Alice | 10001 |
| 2 | Bob | 90001 |

**Table 2: Locations**
| ZipCode | City |
| :--- | :--- |
| 10001 | New York |
| 90001 | Los Angeles |

---

### 4. Boyce-Codd Normal Form (BCNF)

**Rule:**

- Must be in **3NF**.
- For every functional dependency `X -> Y`, `X` must be a **Super Key**.
- It is a stricter version of 3NF.

**Problem (Not in BCNF):**
Scenario: A student can take multiple subjects. For each subject, a student is assigned one professor. A professor teaches only one subject.
Table: **Student_Subject_Prof**
Keys: `(StudentID, Subject)`

| StudentID | Subject | Professor |
| :-------- | :------ | :-------- |
| 1         | Java    | Dr. A     |
| 2         | C++     | Dr. B     |
| 1         | C++     | Dr. B     |

- Dependency: `Professor` -> `Subject` (Because a professor teaches only one subject).
- Here, `Professor` is NOT a Super Key (it doesn't identify the student).
- But `Subject` depends on `Professor`. This violates BCNF.

**Solution (Converted to BCNF):**
Decompose into two tables.

**Table 1: Professor_Subject**
| Professor | Subject |
| :--- | :--- |
| Dr. A | Java |
| Dr. B | C++ |

**Table 2: Student_Professor**
| StudentID | Professor |
| :--- | :--- |
| 1 | Dr. A |
| 2 | Dr. B |
| 1 | Dr. B |

---

## Denormalization

The process of adding redundancy back into the database to improve read performance. It is often used in data warehousing and analytical systems where read speed is more critical than write speed. It avoids the overhead of complex joins.
