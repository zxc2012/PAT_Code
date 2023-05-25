# 3 Data Structure
## Hashmap
| Implement |contains(x) | add(x)|
|-|-|-|
|Bushy BSTs|Θ(log N)|Θ(log N)|
|Separate Chaining Hash Table With No Resizing|Θ(N)|Θ(N)|
|… With Resizing|Θ(1)|Θ(1)|

### Separate Chaining Data Indexed Array

Data is converted into a hash code. The hash code is then reduced to a valid index.

Java’s hashCode() function for Strings
```java
public int hashCode() {// From Left to right: High to Low
    int h = cachedHashValue;
    if (h == 0 && this.length() > 0) {
        for (int i = 0; i < this.length(); i++) {
            h = 31 * h + this.charAt(i);
        }
        cachedHashValue = h;
    }
    return h;
}
```

31: the hashCode base should be a small **prime** to avoid overflow

![20221120134556](https://raw.githubusercontent.com/zxc2012/image/main/20221120134556.png)


![20221120135107](https://raw.githubusercontent.com/zxc2012/image/main/20221120135107.png)

suppose the number of buckets: M, number of items: N

then complexities of contains and add are O(Q = N/M) 

To make them O(1), strategy: When N/M is ≥ 1.5, double M
 

```cpp
bool contains(int x, vector<list<int>>& hash_table){
    int n = hash_table.size();
    int index = (x%n + n)%n;
    list<int>& slot = hash_table[index]; 
    return find(slot.begin(),slot.end(),x)!=slot.end();
}
bool add(int x,vector<list<int>>& hash_table){
    int n = hash_table.size();
    int index = (x%n + n)%n;
    hash_table[index].push_back(x);
}
```

### Open Addressing 

An alternate way to handle collisions is to use open addressing

If target bucket is already occupied, use a different bucket
- Linear probing
    - Use next address, and if already occupied, just keep scanning one by one.
- Quadratic probing
    - Use next address, and if already occupied, try looking 4 ahead, then 9 ahead, then 16 ahead, ...
## List,Set,Map

![20230524204202](https://raw.githubusercontent.com/zxc2012/image/main/20230524204202.png)

## Heap

Binary heap: Binary tree that is complete and obeys heap property
- Min-heap: Every node is less than or equal to both of its children
- Max-heap: Every node is greater than or equal to both of its children

Priority Queue Implementation

| Implement |Ordered Array | Bushy BST| Hash Table|Heap |
|-|-|-|-|- |
|add|Θ(N)|Θ(log N)| Θ(1)|Θ(log N)|
|getSmallest|Θ(1)|Θ(log N)|Θ(N)|Θ(1)|
|removeSmallest|Θ(N)|Θ(log N)| Θ(N)|Θ(log N)|
