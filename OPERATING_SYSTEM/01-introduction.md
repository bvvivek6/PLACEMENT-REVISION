# Module 1: Introduction to Operating Systems

## 1. What is an Operating System?

An Operating System (OS) is system software that manages computer hardware and software resources and provides common services for computer programs. It acts as an intermediary between the user and the computer hardware.

**Goals of OS:**

- **Convenience:** Makes the computer easier to use.
- **Efficiency:** Allows computer system resources to be used in an efficient manner.

## 2. Types of Operating Systems

### a. Batch Operating System

- Jobs with similar needs are batched together and executed as a group.
- **Pros:** Good for large volume of work.
- **Cons:** Lack of interaction between user and job; CPU is often idle (I/O speed < CPU speed).

### b. Time-Sharing / Multitasking OS

- CPU executes multiple jobs by switching among them, but the switches occur so frequently that the users can interact with each program while it is running.
- **Goal:** Minimize response time.

### c. Distributed Operating System

- Multiple central processors serve multiple real-time applications and multiple users.
- Processors communicate with one another through various communication lines.

### d. Real-Time Operating System (RTOS)

- Defined by fixed time constraints. Processing must be done within the defined constraints or the system will fail.
- **Hard RTOS:** Strict deadlines (e.g., Airbag system).
- **Soft RTOS:** Occasional deadline misses are acceptable (e.g., Video streaming).

## 3. Kernel

The kernel is the core component of an OS. It manages the operations of the computer and the hardware.

### Monolithic Kernel

- All OS services run in the kernel space.
- **Pros:** Faster execution.
- **Cons:** If one service crashes, the whole system crashes.
- **Examples:** Linux, Unix.

### Microkernel

- Only essential services (IPC, memory management, scheduling) are in kernel space; others are in user space.
- **Pros:** More stable; easier to extend.
- **Cons:** Slower due to context switching between user and kernel space.
- **Examples:** Minix, QNX.

## 4. System Calls

A system call is the programmatic way in which a computer program requests a service from the kernel of the operating system.

**Types of System Calls:**

- **Process Control:** `fork()`, `exit()`, `wait()`
- **File Management:** `open()`, `read()`, `write()`, `close()`
- **Device Management:** `ioctl()`, `read()`, `write()`
- **Information Maintenance:** `getpid()`, `alarm()`, `sleep()`
- **Communication:** `pipe()`, `shmget()`, `mmap()`

## 5. Dual Mode Operations

To ensure proper execution of the OS, we must distinguish between the execution of operating-system code and user-defined code.

- **User Mode (bit 1):** When the computer system is executing on behalf of a user application.
- **Kernel Mode (bit 0):** When a user application requests a service from the OS (via system call), the system transitions to kernel mode.
