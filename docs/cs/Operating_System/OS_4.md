# 4 File System
## Basic
### Data Structure of File system

Directory Structure: 

A directory is a file containing <file_name:file_number> mappings(each called a directory entry)

File (and directory) defined by header, called "inode"(i = index)

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
