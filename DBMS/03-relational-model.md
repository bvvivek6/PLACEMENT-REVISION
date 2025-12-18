# Relational Model

## Schema and Instances

- **Schema:** The logical structure or design of the database. It rarely changes.
  - _Example:_ `Student(ID, Name, Age, Dept)`
- **Instance:** The actual data stored in the database at a particular moment. It changes frequently.

## Integrity Constraints

Constraints ensure the accuracy and reliability of data in the database.

1.  **Domain Constraint:**

    - Ensures that values in a column fall within a defined range or type.
    - _Example:_ Age must be an integer > 0.

2.  **Entity Integrity Constraint:**

    - The Primary Key cannot be NULL.
    - Each row must be uniquely identifiable.

3.  **Referential Integrity Constraint:**

    - A Foreign Key value must match a Primary Key value in the referenced table or be NULL.
    - Ensures valid relationships between tables.

4.  **Key Constraint:**
    - Ensures that the Primary Key is unique for every record.

## Types of Constraints in SQL

- `NOT NULL`: Ensures a column cannot have a NULL value.
- `UNIQUE`: Ensures all values in a column are different.
- `PRIMARY KEY`: A combination of `NOT NULL` and `UNIQUE`. Uniquely identifies each row.
- `FOREIGN KEY`: Uniquely identifies a row/record in another table.
- `CHECK`: Ensures that the values in a column satisfy a specific condition.
- `DEFAULT`: Sets a default value for a column if no value is specified.
