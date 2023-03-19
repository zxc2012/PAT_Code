# 4 File System
## Basic
### Data Structure of File system

Directory Structure: 

A directory is a file containing <file_name:file_number> mappings(each called a directory entry)

File (and directory) defined by header, called "inode"(i = index)

Each inode contains file attributes (permissions, timestamps, owner) and the index blocks

![20230313212759](https://raw.githubusercontent.com/zxc2012/image/main/20230313212759.png)

Open performs **Name Resolution**: Translates path name into file number

Read and Write operate on the *file number*

![20230313214926](https://raw.githubusercontent.com/zxc2012/image/main/20230313214926.png)

### File Storage on Disk

![20230313213841](https://raw.githubusercontent.com/zxc2012/image/main/20230313213841.png)

Super Block

- number of blocks
- size of data blocks
- free-block count
- location of the file descriptor of the root directory

## Directory Structure

To acclerate the process of finding a file and enable sharing, use DAG

![20230313220501](https://raw.githubusercontent.com/zxc2012/image/main/20230313220501.png)

Hard Links and Symbolic Links

- Hard links: Both directory entries point to the same inode
    - The file may have a different name in each directory
- Symbolic links: One directory entry points to the file’s inode, Other directory entries contains the "path"
    - inode different

## File Allocation
### Contiguous Allocation

All blocks in a file are contiguous on the disk, Search bit map or linked list to locate a space

File header: 
- first sector in file
- number of sectors

Pros
- Simple to implement (only needs starting block & length of file)
- Fast sequential access
- Easy random access

Cons
- External fragmentation
- hard to grow files when new file is inserted into a hole

### Linked List Allocation

Each file is a sequence of blocks. File header points to 1st block on disk, each block points to next

![20230317204648](https://raw.githubusercontent.com/zxc2012/image/main/20230317204648.png)

Pro
- No external fragmentation
- easy to grow files

Cons
- bad random access
- unreliable: losing a block means losing the rest

Variation: File Allocation Table(FAT)

FAT is linked list 1-1 with blocks, follow list to get block number, unused blocks marked free

Ex: file_write 31, < 3, y > (y: offset within block)
- Grab free block
- Linking them into file

![20230319212139](https://raw.githubusercontent.com/zxc2012/image/main/20230319212139.png)

FAT directory: Directory entry needs only the starting block number

![20230319215117](https://raw.githubusercontent.com/zxc2012/image/main/20230319215117.png)

Format a disk: Zero the blocks, mark FAT entries "free"

Quick format: Mark FAT entries "free"

Used in MS-DOS

Pros:
- Easy to delete a file
- Easy to append to a file

Cons:
- Small file access slow(seek time latency between blocks)
- Random access slow(sequential search)
- memory overhead
    - 20 GB disk size, 1 KB block size, 4 bytes FAT entry size. Need 80MB to store FAT

### Indexed Allocation

Berkeley F(Fast)FS / UNIX FS

inode
- Metadata(File owner, access permissions, access times, …)
- Small Files: 12 Direct pointers With 4KB blocks => max size of 48KB files
- Large Files: Indirect block pointers, each block supports 1K ptrs
    - indirected block pointer => max 4 MB
    - Doubly indirected block pointer => max 4 GB
    - Triply indirected block pointer => max 4 TB

![20230319215757](https://raw.githubusercontent.com/zxc2012/image/main/20230319215757.png)

Pros
- Efficient storage for both small and large files
- Locality for both small and large files
- Locality for metadata and data
- No defragmentation necessary!

Cons
- Inefficient for tiny files (a 1 byte file requires both an inode and a data block)
- Inefficient encoding when file is mostly contiguous on disk
- Need to reserve 10-20% of free space to prevent fragmentation