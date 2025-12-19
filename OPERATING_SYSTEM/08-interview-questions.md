# Module 8: Interview Questions

## Common OS Interview Questions

1.  **What is the difference between a Process and a Thread?**

    - _Answer:_ A process is an executing program with its own memory space. A thread is a unit of execution within a process that shares the process's memory space but has its own stack and registers. Context switching is faster for threads.

2.  **What is a Deadlock? What are the necessary conditions?**

    - _Answer:_ Deadlock is a situation where a set of processes are blocked because each is holding a resource and waiting for another resource held by another process. Conditions: Mutual Exclusion, Hold and Wait, No Preemption, Circular Wait.

3.  **Explain the difference between Paging and Segmentation.**

    - _Answer:_ Paging divides memory into fixed-size blocks (frames/pages) to avoid external fragmentation. Segmentation divides memory into variable-sized blocks (segments) based on logical units (function, stack, etc.) to support the user's view of memory.

4.  **What is a Semaphore? Difference between Binary Semaphore and Mutex?**

    - _Answer:_ A semaphore is a signaling mechanism (integer) used for synchronization. A Mutex is a locking mechanism. Key difference: Mutex involves ownership (only the locker can unlock), while a Semaphore can be signaled by any process.

5.  **What is Thrashing?**

    - _Answer:_ Thrashing occurs when the system spends more time paging (swapping pages in and out) than executing the actual process, leading to low CPU utilization. It happens when the degree of multiprogramming is too high.

6.  **What is a System Call?**

    - _Answer:_ A programmatic way for a user program to request a service from the kernel (e.g., reading a file, creating a process).

7.  **What is Context Switching?**

    - _Answer:_ The process of saving the state of the currently running process and restoring the state of the next process to run. It allows multitasking but adds overhead.

8.  **Explain Belady's Anomaly.**

    - _Answer:_ In some page replacement algorithms (like FIFO), increasing the number of page frames can result in an increase in the number of page faults.

9.  **What is the difference between Preemptive and Non-Preemptive Scheduling?**

    - _Answer:_ In preemptive scheduling, the OS can forcibly take the CPU away from a running process (e.g., Round Robin). In non-preemptive, the process keeps the CPU until it voluntarily releases it or terminates (e.g., FCFS).

10. **What is Virtual Memory?**

    - _Answer:_ A technique that allows the execution of processes that are not completely in physical memory. It gives the illusion of a larger memory than physically available.

11. **What is a Zombie Process?**

    - _Answer:_ A process that has finished execution but still has an entry in the process table because its parent has not yet read its exit status (via `wait()`).

12. **What is an Orphan Process?**
    - _Answer:_ A process whose parent has terminated, but it is still running. It is usually adopted by the `init` process.
