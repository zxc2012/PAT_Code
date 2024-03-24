# 2 Synchronization
## Race Condition

we need to make threads coordinate with each other to ensure **mutual exclusion** in accessing **critical sections** of code

### Lock

Locks provide two atomic operations

- Lock.acquire() – wait until lock is free; then mark it as busy
- Lock.release() – mark lock as free

Problem: SpinLock consumes cycles while waiting

```cpp
TSL(&address) { //test and set lock 
    result = M[address]; // return result from “address” and
    M[address] = 1; // set value at “address” to 1
    return result;
}
int value = 0; // Free
Acquire() {
    while (TSL(&value)) {}; // spin while busy
}
Release() {
    value = 0; // atomic store
}
```

Better Locks

```cpp
int guard = 0;
int value = FREE;
Acquire() {
    // Short busy-wait time
    while (TSL(guard));
    if (value == BUSY) {
        put thread on wait queue;
        run_new_thread() & guard = 0;
    } else {
        value = BUSY;
        guard = 0;
    }
}
Release() {
    // Short busy-wait time
    while (TSL(guard));
    if anyone on wait queue {
        take thread off wait queue
        Place on ready queue;
    } else {
        value = FREE;
    }
    guard = 0;
}
```

### semaphore

semaphore ['sɛməfɔr]`sema- :signal,phoro:carry,bring`

a semaphore has a non-negative integer value and supports the following two operations:
- P() or down(): atomic operation that waits for semaphore to become positive, then decrements it by 1
- V() or up(): an atomic operation that increments the semaphore by 1

P() stands for probe (to test) and V() stands for “verhogen” (to increment) in Dutch

### Producer-Consumer Problem

- Buffer Empty: The producer needs to first add a message to the shared buffer before the consumer can remove it
- Buffer Full: The producer needs to wait for the consumer to catch up

```cpp
semaphore mutex = 1, empty = N, full = 0;
Producer(item){
    empty.P();
    mutex.acquire();//1,2 注意顺序
    Enqueue(item);
    mutex.release();
    full.V(); //4,5顺序可颠倒
}
Consumer() {
    full.P();
    mutex.acquire();
    item = Dequeue();
    mutex.release();
    empty.V();
    return item;
}
```

- wait->yield->schedule
- interrupt->schedule

![20220531174332](https://raw.githubusercontent.com/zxc2012/image/main/20220531174332.png)

### Monitors

Monitor
- Encapsulation
    - Local data variables are accessible only via the monitor’s entry methods
- Mutual exclusion
    - only one thread can be active in a monitor at any time
    - every method starts with lock and end with unlock

Condition Variables
- condition.wait(): a thread exits the monitor(relese lock), waits for the *condition* variable to hold, and enters the monitor(Reacquire lock) again when it does
- condition.signal(): signals (wakes up) a waiting thread on the *condition* variable, so that it can try to enter the monitor
- condition.broadcast(): signals (wakes up) all waiting threads on the *condition* variable, so that they can all try to enter the monitor

```cpp
// Wrong Answer
mutex lock = unlocked;
Condition full,empty;
Producer(item){
    lock.acquire();
    if(buffer_full)full.wait();//wait when buffer is full
    Enqueue(item);
    empty.signal();
    lock.release();
}
Consumer() {
    lock.acquire();
    if(buffer_empty)empty.wait();//wait when buffer is empty
    item = Dequeue();
    full.signal();
    lock.release();
    return item;
}
```

The Producer is running in the monitor.It adds a message to an empty shared buffer,signals a waiting Consumer thread, waking it up. At this time, the Producer and Consumer cannot both run inside the monitor.

(1)Hoare Semantics

The signaled thread, B, enters the monitor immediately,then back to A(The signaling thread)

When a thread call signal():
- It releases the lock and the OS context-switches to the waiter, which acquires the
lock immediately
- When waiter releases lock, the OS switches back to signaler

(2)**Mesa Semantics**

The signaled thread is awakened,it will have to compete against all other threads for the monitor lock.

**Problem previously**: 

- When a thread is woken up by signal(), it is simply marked as eligible to run. 
- Another thread could be scheduled first and "sneak in" to empty/full the queue

Solution: if->while

```cpp
mutex lock = unlocked;
Condition full,empty;
Producer(item){
    lock.acquire();
    while(buffer_full)full.wait();//wait when buffer is full
    Enqueue(item);
    empty.signal();
    lock.release();
}
Consumer() {
    lock.acquire();
    while(buffer_empty)empty.wait();//wait when buffer is empty
    item = Dequeue();
    full.signal();
    lock.release();
    return item;
}
```

## DeadLock

![20230323204655](https://raw.githubusercontent.com/zxc2012/image/main/20230323204655.png)

Deadlock => starvation but not vice versa

- Starvation: thread waits indefinitely
- Deadlock: circular waiting for resources

Starvation can end. Deadlock can’t end without external intervention

### Resource-Allocation Graph

A set of Threads $T_1$, $T_2$, . . ., $T_n$/ Resource types $R_1$，$R_2$, . . ., $R_m$(CPU cycles, memory space, I/O devices)

Each thread utilizes a resource as follows: Request() / Use() / Release()

- request edge – directed edge $T_1$ -> $R_j$
- assignment edge – directed edge $R_j$ -> $T_i$

![20230323212735](https://raw.githubusercontent.com/zxc2012/image/main/20230323212735.png)

### Four requirements

- **Mutual exclusion**: Only one thread at a time can use a resource.
- **Hold and wait**: Thread holding at least one resource is waiting to acquire additional resources held by other threads
- **No preemption**: Resources are released only voluntarily by the thread holding the resource, after thread is finished with it
- **Circular wait**
    - There exists a set {T1, …, Tn} of waiting threads
    - T1 is waiting for a resource that is held by T2
    - T2 is waiting for a resource that is held by T3
    - ...
    - Tn is waiting for a resource that is held by T1

### Techniques for addressing deadlock

- **Deadlock prevention**: breaks any one of four requirements
    - No mutual exclusion: No Sharing of resources (totally independent threads)
    - No hold and wait:
        - Allow process to request resources only when the process has none: starvation possible
        - Make all threads request everything they’ll need at the beginning: Low resource utilization
    - Allow preemption: On collision, back off and retry
    - No circular wait: Force all threads to request resources in a particular order preventing any cyclic use of resources
- **Deadlock recovery**: let deadlock happen, and then figure out how to recover from it
    - Terminate thread, force it to give up resources
    - Preempt resources without killing off thread
    - Roll back actions of deadlocked threads
- **Deadlock avoidance**: prevent system from reaching an *unsafe* state
    - When a thread requests a resource, OS checks if it would result in deadlock an unsafe state
        - If not, it grants the resource right away
        - If so, it waits for other threads to release resources
- **Deadlock denial**: ignore the possibility of deadlock

Deadlock avoidance: Safe state(System can delay resource acquisition to prevent deadlock), Unsafe state(Threads can unavoidably lead to deadlock/Deadlock exist)

### The Dining Philosopher

Five Philosopher sit at a table

![20220520215436](https://raw.githubusercontent.com/zxc2012/image/main/20220520215436.png)

```python
def philosopher(int i):
    while true:
        think()
        Pickup left fork
        Pickup right fork
        eat()
        Put down left fork
        Put down right fork
```

DeadLock

It may happen that all five philosophers take their left fork at the same time, and then try to take
their right fork, which is taken by a neighbouring philosopher

Solution

```python
semaphore forks[5]= {1,1,1,1,1}
def pickup_fork(int i):
    forks[i].down()
def putdown_fork(int i):
    forks[i].up()

def pickup_forks(int i):
    if i == 4:
        pickup_fork((i+1) modulo 5)
        pickup_fork(i)
    else:
        pickup_fork(i)
        pickup_fork((i+1) modulo 5)
def putdown_forks(int i):
    putdown_fork(i)
    putdown_fork((i+1) modulo 5)
```