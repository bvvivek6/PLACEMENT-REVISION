# Module 3: Concurrency & Synchronization

## 1. Race Condition

A situation where several processes access and manipulate the same data concurrently and the outcome of the execution depends on the particular order in which the access takes place.

## 2. Critical Section Problem

A code segment where shared variables are accessed. To avoid race conditions, we need to ensure that when one process is executing in its critical section, no other process is allowed to execute in its critical section.

**Requirements for Solution:**

1.  **Mutual Exclusion:** Only one process in Critical Section (CS) at a time.
2.  **Progress:** If no process is in CS, and some want to enter, the selection cannot be postponed indefinitely.
3.  **Bounded Waiting:** A bound must exist on the number of times other processes are allowed to enter their CS after a process has made a request to enter its CS and before that request is granted.

## 3. Synchronization Tools

### a. Mutex (Mutual Exclusion Object)

- A locking mechanism used to synchronize access to a resource.
- Only the process that locked the mutex can unlock it.
- **Operations:** `acquire()` (lock), `release()` (unlock).

### b. Semaphores

- A signaling mechanism (integer variable) used to manage concurrent processes.
- **Operations:** `wait()` (P) and `signal()` (V).
- **Types:**
  - **Binary Semaphore:** Value 0 or 1. Similar to Mutex.
  - **Counting Semaphore:** Value ranges over an unrestricted domain. Used to control access to a resource with multiple instances.

### c. Code Example: Mutex Lock (C)

Here is a practical example using C threads (`pthread`) to demonstrate how a Mutex prevents race conditions when accessing a shared variable.

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int balance = 200; // Shared resource
pthread_mutex_t lock; // Mutex declaration

void* deposit(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock); // Critical Section Start
        balance++;
        pthread_mutex_unlock(&lock); // Critical Section End
    }
    return NULL;
}

void* withdraw(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock); // Critical Section Start
        balance--;
        pthread_mutex_unlock(&lock); // Critical Section End
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&t1, NULL, deposit, NULL);
    pthread_create(&t2, NULL, withdraw, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    printf("Final Balance: %d\n", balance);
    return 0;
}
```

**Explanation:**

- Without `lock.acquire()` and `lock.release()`, the `balance` update would be a race condition. The read-modify-write operation (`balance.value + 1`) is not atomic.
- The **Lock** ensures that only one process enters the critical section (modifying `balance`) at a time.

## 4. Deadlock

A situation where a set of processes are blocked because each process is holding a resource and waiting for another resource acquired by some other process.

### Necessary Conditions (Coffman Conditions)

Deadlock can arise if four conditions hold simultaneously:

1.  **Mutual Exclusion:** At least one resource must be held in a non-sharable mode.
2.  **Hold and Wait:** A process must be holding at least one resource and waiting to acquire additional resources held by other processes.
3.  **No Preemption:** Resources cannot be preempted.
4.  **Circular Wait:** A set of processes $\{P_0, P_1, ..., P_n\}$ exists such that $P_0$ waits for $P_1$, $P_1$ waits for $P_2$, ..., $P_n$ waits for $P_0$.

### Deadlock Handling

#### a. Deadlock Prevention

Ensure at least one of the 4 conditions cannot hold.

- _Example:_ Attack Circular Wait by imposing a total ordering of all resource types.

#### b. Deadlock Avoidance

The OS needs a priori information about resource usage.

- **Banker's Algorithm:** Checks if allocating resources leaves the system in a **Safe State**. If yes, grant request; otherwise, wait.

#### c. Deadlock Detection & Recovery

- Allow deadlock to occur, detect it (using Wait-for graph or resource allocation graph), and recover.
- **Recovery:** Abort all deadlocked processes OR Abort one by one until deadlock cycle is eliminated.

## 5. Classic Problems

- **Producer-Consumer Problem:** Bounded buffer problem.
- **Dining Philosophers Problem:** 5 philosophers, 5 chopsticks. Need 2 to eat.
- **Readers-Writers Problem:** Multiple readers can read simultaneously, but if a writer is writing, no other process can access.
