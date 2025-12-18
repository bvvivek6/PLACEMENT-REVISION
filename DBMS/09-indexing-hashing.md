# Indexing and Hashing

## Indexing

Indexing is a data structure technique used to quickly locate and access the data in a database. Indexes are created using a few database columns.

### Types of Indexing

1.  **Primary Index:** Defined on an ordered data file. The data file is ordered on a key field. The key field is generally the primary key of the relation.
2.  **Secondary Index:** Defined on a non-ordering field of the data file.
3.  **Clustered Index:** Defined on an ordered data file. The data file is ordered on a non-key field.
4.  **Dense Index:** An index record appears for every search key value in the file.
5.  **Sparse Index:** An index record appears for only some of the values in the file.

### B-Trees and B+ Trees

- **B-Tree:** A self-balancing tree data structure that maintains sorted data and allows searches, sequential access, insertions, and deletions in logarithmic time.
- **B+ Tree:** An extension of B-Tree which allows efficient retrieval of data.
  - All data pointers are stored only at the leaf nodes.
  - Leaf nodes are linked together (Linked List), making range queries very efficient.
  - Internal nodes store only keys for navigation.
  - _Most widely used indexing structure in DBMS._

## Hashing

Hashing is a technique to directly calculate the location of a data record on the disk without using an index structure.

### Static Hashing

- The number of buckets is fixed.
- **Hash Function:** Maps a search key to a bucket address.
- **Collision:** When two different keys map to the same bucket. Handled by chaining or open addressing.

### Dynamic Hashing (Extendible Hashing)

- The number of buckets grows or shrinks dynamically as the database grows or shrinks.
- Solves the problem of bucket overflow in static hashing.
