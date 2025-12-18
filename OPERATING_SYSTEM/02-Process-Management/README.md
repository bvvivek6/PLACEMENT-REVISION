# Module 2: Process Management

## 1. Process vs Thread

| Feature           | Process                                             | Thread                                                                                                              |
| :---------------- | :-------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------ |
| **Definition**    | A program in execution.                             | A lightweight process; a unit of CPU utilization.                                                                   |
| **Resources**     | Has its own memory space (Code, Data, Heap, Stack). | Shares memory space with other threads of the same process (Code, Data, Heap), but has its own Stack and Registers. |
| **Communication** | Slow (IPC mechanisms needed).                       | Fast (Shared memory).                                                                                               |
| **Overhead**      | High context switching overhead.                    | Low context switching overhead.                                                                                     |
| **Isolation**     | Isolated from other processes.                      | Not isolated; one thread crash can crash the process.                                                               |

## 2. Process Lifecycle (States)

A process goes through various states during its execution:

1.  **New:** The process is being created.
2.  **Ready:** The process is waiting to be assigned to a processor.
3.  **Running:** Instructions are being executed.
4.  **Waiting (Blocked):** The process is waiting for some event (like I/O completion).
5.  **Terminated:** The process has finished execution.

![Process State Diagram](https://upload.wikimedia.org/wikipedia/commons/thumb/8/83/Process_states.svg/1200px-Process_states.svg.png)
_(Note: Diagram representation)_

## 3. Process Control Block (PCB)

Data structure used by the OS to store all information about a process.

- Process ID (PID)
- Process State
- Program Counter (Address of next instruction)
- CPU Registers
- CPU Scheduling Information
- Memory Management Information
- I/O Status Information

## 4. CPU Scheduling Algorithms

**Goal:** Maximize CPU utilization and throughput, minimize turnaround time, waiting time, and response time.

### a. First-Come, First-Served (FCFS)

- **Criteria:** Arrival Time.
- **Mode:** Non-preemptive.
- **Pros:** Simple.
- **Cons:** Convoy Effect (short process behind long process waits a long time).

### b. Shortest Job First (SJF)

- **Criteria:** Burst Time (Execution time).
- **Mode:** Non-preemptive.
- **Pros:** Optimal average waiting time.
- **Cons:** Difficult to predict burst time; Starvation possible for long processes.

### c. Shortest Remaining Time First (SRTF)

- Preemptive version of SJF.

### d. Round Robin (RR)

- **Criteria:** Time Quantum.
- **Mode:** Preemptive.
- **Pros:** Fair; good response time.
- **Cons:** Performance depends heavily on time quantum size. (Too large = FCFS, Too small = High context switch overhead).

### e. Priority Scheduling

- **Criteria:** Priority number.
- **Mode:** Preemptive or Non-preemptive.
- **Cons:** Starvation (low priority processes may never execute).
- **Solution:** Aging (gradually increase priority of waiting processes).

## 5. Context Switching

The process of storing the state of a process or thread, so that it can be restored and resume execution at a later point. This allows multiple processes to share a single CPU.

- **Overhead:** It is pure overhead; the system does no useful work while switching.
