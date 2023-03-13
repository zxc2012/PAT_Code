# 6 Virtual Memory
## Memory Basic
### Memory Multiplexing

MMU(Memory Management Unit) converts virtual to physical

![20230221203545](https://raw.githubusercontent.com/zxc2012/image/main/20230221203545.png)

Different Processes/Threads share the same hardware
- Need to multiplex CPU (Scheduling)
- Need to multiplex use of Memory (Virtual Memory)

Important Aspects of Memory Multiplexing
- Multiplexing: Allow multiple processes to simultaneously occupy memory
- Protection: Prevent access to private memory of other processes
- Translation: Give each program the illusion that it has its own private address space, and then translate accesses from virtual to physical

![20220603203635](https://raw.githubusercontent.com/zxc2012/image/main/20220603203635.png)

### Base & Bound Machine

![20221126210452](https://raw.githubusercontent.com/zxc2012/image/main/20221126210452.png)

Problems
- May need more space than segment allows
- External Fragmentation: Free chunks between allocated regions

    ![20230105233347](https://raw.githubusercontent.com/zxc2012/image/main/20230105233347.png)

- Internal Fragmentation: Space inside allocated address space may not be fully used

    ![20230105233503](https://raw.githubusercontent.com/zxc2012/image/main/20230105233503.png)

### Simple Segmentation

if I have 16 bit address with 4 segments (code, data, stack, heap), use 2 segment bits

![20230221215032](https://raw.githubusercontent.com/zxc2012/image/main/20230221215032.png)

Pros: Minimize internal fragmentation

Cons: Still External fragmentation

## Address Translation
### Simple Paging

Instead of having segments of various sizes, divide physical memory and virtual memory into equal units called *pages*
- Pages are the same size in both virtual and physical memory, and RAM is an integer multiple of pages
- Avoids internal fragmentation: Each program has access to one or more pages(do not have to be contiguous)

Virtual/Physical addresses can be broken into page number + offset(much likeT/I/O)

- Memory Size = $2^{Address}$ Bytes
- Page size Bytes = $2^{Offset}$ Bytes
- VPN/PPN = log_2(# of pages) = log_2(Memory Size/page size)

Virtual addresses: Divided into pages indexed by virtual page number(VPN)

![20220603214329](https://raw.githubusercontent.com/zxc2012/image/main/20220603214329.png)

Physical addresses: Divided into pages indexed by phisical page number(PPN) or frame number

![20220603214355](https://raw.githubusercontent.com/zxc2012/image/main/20220603214355.png)

Example 

![20220603214957](https://raw.githubusercontent.com/zxc2012/image/main/20220603214957.png)

#### Page Table Entry

Each program has a page table, whose address store in PTBR(Page Table Base Register)

PTBR value saved/restored in PCB on context switch

- Dirty bit: Page has been modified recently
- Valid bit
    - 1: virtual page is in physical memory
    - 0: OS needs to fetch page from disk(Page Fault)
- Permission bits: Access Rights checked on every access to see if allowed (else protection fault)
    - Read, Write, Executable
- PPN

![20220603215849](https://raw.githubusercontent.com/zxc2012/image/main/20220603215849.png)

Example: 

If we ignore the valid and permission bits, assume that page table entry only contains PPN

Number of pages needed by Page table = $\frac{2^{VPN}\times PPN}{8\times pagesize}$

#### Problems

32 bit processor, 12 bit offset-> 4KB page size
> Memory = $2^{20}$ * 4 bytes(20 + valid bit + permission bits) = 4 MB

64 bit processor, 12 bit offset
> Memory = $2^{52}$ * 8 bytes(52 + ...) = ridiculous!

Problems:
- can be really large (span multiple pages), and sparsely populated
- have to load the entire page table(may only need sections)

### Multi-Level Paging

![20221127214634](https://raw.githubusercontent.com/zxc2012/image/main/20221127214634.png)

![20230225224712](https://raw.githubusercontent.com/zxc2012/image/main/20230225224712.png)

### Inverted Page Table

Physical memory < Virtual memory: Much of process space may be out on disk or not in use

![20230221222300](https://raw.githubusercontent.com/zxc2012/image/main/20230221222300.png)

use a hash table
- Size Directly related to amount of physical memory
- Very attractive option for 64-bit address spaces: PowerPC, UltraSPARC, IA64

Cons
- Complexity of managing hash chains: Often in hardware!
- Poor cache locality of page table

### Address Translation Comparison

<table>
<tr><th></th><th>Advantages</th><th>Disadvantages</th></tr>
<tr><td>Simple Segmentation</td><td>Fast context switching (segment map maintained by CPU)</td><td>External fragmentation</td></tr>
<tr><td>Simple Paging</td><td>1.No external fragmentation 2.Fast and easy allocation</td><td>1.Large table size(~ virtual memory) 2.Internal fragmentation</td></tr>
<tr><td>Multi-Level Paging</td><td>1.Table size ~ # of pages in virtual memory 2.Fast and easy allocation</td><td>Multiple memory references per page access</td></tr>
<tr><td>Inverted Page Table</td><td>Table size ~ # of pages in physical
memory</td><td>1.Hash function more complex 2.No cache locality of page table</td></tr>
</table>

## Translation Lookaside Buffer (TLB)

MMU Problem: 2+ physical memory accesses per data access = SLOW

Build a separate cache for the Page Table: TLB

**TLB vs Cache**

- TLBs usually small, typically 32–128 entries
- TLB access time comparable to cache (much faster than accessing main memory)
- TLBs usually are fully/highly associativity

![20221127220733](https://raw.githubusercontent.com/zxc2012/image/main/20221127220733.png)

![20221127220842](https://raw.githubusercontent.com/zxc2012/image/main/20221127220842.png)

**Page Locality**

- Instruction accesses spend a lot of time on the same page (since accesses sequential)
- Stack accesses have definite locality of reference

### TLB Entry Format

- Valid: whether that TLB ENTRY is valid (unrelated to PT)
- Ref: Used to implement LRU, set when page is accessed, cleared periodically by OS
- Access Rights: Data from the PT
- Dirty: Consistent with PT
- PPN: Data from PT
- VPN: Data from PT

## Page Replacement Policy

### Basic Policy

- Random: Pick random page for every replacement
- FIFO: Replace page we miss least recently
- MIN: Replace page that will be used farthest in future
- LRU: Replace page we used(hit & miss) least recently(approximation to MIN)

How to implement LRU?

Maintain a linked list. On each use, remove page from list and place at head, LRU page is at tail

Problems: Many instructions for each hardware access

### Clock Algorithm

To approximate LRU, arrange all pages in circular list. Maintain a hardware *use* bit per physical page 

![20221127220842](https://raw.githubusercontent.com/zxc2012/image/main/20230301165826.png)

On reference: set use bit

On page fault:
- Advance clock hand
- Check use bit: 1 means used recently, clear and leave alone; The first 0 is selected candidate for replacement

Problem: Replace an old page, not the oldest page

### Nth Chance Clock Algorithm

OS keeps counter per page: # sweeps

On page fault, OS checks use bit:
- 1: clear use and also clear counter (used in last sweep)
- 0: increment counter. if count=N,replace page

Large N: good approximation

Small N: more efficient

## Paging Questions
### Page Sharing

![20230226212443](https://raw.githubusercontent.com/zxc2012/image/main/20230226212443.png)

Senario
- Different processes running same binary
- User-level system libraries (execute only)
- Shared-memory segments between different processes
### Contex Switch

Address Space just changed, so TLB entries no longer valid

Options

1. Invalidate TLB: simple but might be expensive 
2. Include ProcessID in TLB: needs hardware

### Demand Paging

```py
(Success, TlbEntry) = TLB_Lookup(VPN)
if (Success == True) # TLB Hit
    if (CanAccess(TlbEntry.ProtectBits) == True)
        Register = AccessMemory(PhysAddr)
    else
        RaiseException(PROTECTION_FAULT) # Protection Fault
else #TLB Miss
    PTEAddr = PTBR + (VPN * sizeof(PTE))
    PTE = AccessMemory(PTEAddr)
if (PTE.Valid == False)  # Invalid PTE
    RaiseException(SEGMENTATION_FAULT)
else
    if (CanAccess(PTE.ProtectBits) == False)
        RaiseException(PROTECTION_FAULT)
    else if (PTE.Present == True) # Retry
        TLB_Insert(VPN, PTE.PFN, PTE.ProtectBits)
        RetryInstruction()
    else if (PTE.Present == False) # Page Fault
        RaiseException(PAGE_FAULT)
```

#### Protection Fault

Page table entry has protection bits inconsistent with operation
- Read/write/execute operation not permitted on the page

Normally, OS sends segmentation fault, kills thread

#### Page Fault

Suppose user references page with invalid PTE

1. Load the page off the disk into a free page of memory. Switch to some other process while we wait

    If memory full, replace page (LRU). If old page modified, write back to disk. Change its PTE and any cached TLB to be invalid

2. Maps page table entry in page table to frame, makes it present
    
3. Interrupt thrown(switch to thread from original faulting location) when page loaded and the process’ page table is updated.
    
    Continuous swapping between disk and memory called "thrashing"

![20230226222439](https://raw.githubusercontent.com/zxc2012/image/main/20230226222439.png)

#### Other Scenarios

Process Fork
- Create a copy of the page table
- Entries refer to parent pages – NO-WRITE
- Shared read-only pages remain shared
- Copy page on write (different stack, heap)

Exec
- Only bring in parts of the binary in active use
- Do this on demand