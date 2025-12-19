# Module 5: Storage Management

## 1. File System

- **File:** A named collection of related information that is recorded on secondary storage.
- **Directory Structure:**
  - Single-level
  - Two-level
  - Tree-structured
  - Acyclic-graph
  - General graph

## 2. File Allocation Methods

How disk blocks are allocated for files.

### a. Contiguous Allocation

- Each file occupies a set of contiguous blocks on the disk.
- **Pros:** Simple, fast sequential access.
- **Cons:** External fragmentation, hard to extend file size.

### b. Linked Allocation

- Each file is a linked list of disk blocks.
- **Pros:** No external fragmentation.
- **Cons:** Slow random access, space overhead for pointers.

### c. Indexed Allocation

- Brings all pointers together into the index block.
- **Pros:** Supports direct access, no external fragmentation.
- **Cons:** Overhead of index block.

## 3. Disk Scheduling Algorithms

Goal: Minimize seek time (time to move disk arm to desired cylinder).

### a. FCFS (First-Come, First-Served)

- Simple and fair.
- Does not provide fastest service.

### b. SSTF (Shortest Seek Time First)

- Selects the request with the minimum seek time from the current head position.
- May cause starvation of some requests.

### c. SCAN (Elevator Algorithm)

- Disk arm starts at one end of the disk, and moves toward the other end, servicing requests along the way. When it reaches the other end, the direction is reversed.

### d. C-SCAN (Circular SCAN)

- Like SCAN, but when it reaches the other end, it immediately returns to the beginning of the disk without servicing any requests on the return trip.
- Provides more uniform wait time.

## 4. RAID (Redundant Array of Independent Disks)

- **RAID 0:** Striping (Performance, No Redundancy).
- **RAID 1:** Mirroring (Redundancy, High Cost).
- **RAID 5:** Block Interleaved Distributed Parity (Good balance of Performance, Redundancy, Cost).
- **RAID 6:** Double Distributed Parity.
- **RAID 10:** Stripe of Mirrors (RAID 1 + RAID 0).
