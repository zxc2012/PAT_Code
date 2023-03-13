# 3 Scheduling
## Basic

Design Objectives
- Response Time: the time from when the job
arrives to the first time it is scheduled($T_{firstrun}-T_{arrival}$)
- Turnaround time: total time needed to complete a
job($T_{completion}-T_{arrival}$)
- Fairness: give each thread its fair share

Assumptions

- Each job runs for the same amount of time
- All jobs arrive at the same time
- Once started, each job runs to completion
- All jobs only use the CPU (no I/O)
- The run-time of each job is known

## Policies
### FCFS

First-Come-First-Served

**Relax assumption 1: jobs take the same amount of time**

Consider $T_1$,$T_2$,$T_3$ sequence of scheduling

- Average response time for (1): 17
- Average response time for (2): 3

![20220531215934](https://raw.githubusercontent.com/zxc2012/image/main/20220531215934.png)

Problem: Short processes stuck behind long processes

### SJF

Shortest Job First->We can choose(2)

**Relax assumption 2: All jobs arrive at the same time**

### SRTF

Shortest Remaining Time First

![20220601202121](https://raw.githubusercontent.com/zxc2012/image/main/20220601202121.png)

**Relax assumption 3: Once started, each job runs to completion**

### RR

Round Robin

- Give out small units of CPU time ("time quantum")
- When quantum expires, preempt, and schedule
    - Round Robin: add to end of the queue
- Each of N processes gets ~1/N of CPU (in window)
    - With quantum length Q ms, process waits at most (N-1)*Q ms to run again
- Downside: More context switches

![20220601210906](https://raw.githubusercontent.com/zxc2012/image/main/20220601210906.png)

**Relax assumption 4: All jobs only use the CPU (no I/O)**

with SRTF, we treat each sub-job as an independent one

![20220601211540](https://raw.githubusercontent.com/zxc2012/image/main/20220601211540.png)

**Relax assumption 5: The run-time of each job is known**

### MLFQ

#### Static Priority Scheduling

![20220602211459](https://raw.githubusercontent.com/zxc2012/image/main/20220602211459.png)

Setting priorities: I/O bound (interactive) jobs need higher
priorities, and the priorities for CPU bound jobs should be lower.

- If Priority(A) > Priority(B), A runs
- If Priority(A) = Priority(B), A & B run in RR

Problem: 
- Low priority thread might never run
- Deadlock: A high-priority thread H becomes ready to run when a low-priority thread L is in the critical section, H waits forever->Medium Priority will be chosen

DeadLock Solution: **Priority inheritance**

low-priority thread inherits the priority of the high-priority thread when it has the lock

#### Multi-Level Feedback Queue

- If Priority(A) > Priority(B), A runs
- If Priority(A) = Priority(B), A & B run in RR
- When a job enters, it has the highest priority
- Job Exceeds Quantum: Drop to lower queue(CPU Bound)
- Job Doesn't Exceed Quantum: Raise to higher queue(I/O Bound)
- After some time period, move all the jobs in the system to the topmost queue (CPU-bound jobs may never run)

## More scheduling policy
### Linux O(1)

- 140 priorities in total, 200 ms (highest priority) to 10 ms time slice
- *Active* and *expired* queues at each priority,each element in the queue is a linked list of threads
- threads in a certain priority: round-robin fashion
- when a thread’s time slice expires, it is moved to the expired array, with an adjustment to its priority level

Static priority set by "nice": initial priority

- nice values range from -20 to 19 (mapped to 100 to 139 in the runqueue)
- higher value -> lower priority
- default priority: 0 (mapped to 120)
- can be changed via the nice() system call

*Active* and *expired* separate priority queues:

The active and expired priority arrays will be swapped when there are no threads in the active array

### Multiprocessor scheduling

- Migrating jobs from one CPU to another requires a cost of invalidating and repopulating caches — so we don’t wish to do this often
    
    **Cache affinity**: try to avoid migration of jobs from one CPU to another(right)
    ![20221126203424](https://raw.githubusercontent.com/zxc2012/image/main/20221126203424.png)

- We don’t wish to leave a CPU idle while another CPU is too busy with all its jobs
    
    **Load balancing**: try to keep the workload evenly distributed
