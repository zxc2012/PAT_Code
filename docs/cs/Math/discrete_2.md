# 2 Graph
## Graph
### Definition

Graph: G = (V,E)
- V: set of vertices.
- $E\subseteq V\times V$(set of edges)

if $e=\lbrace u,v\rbrace\in E$ and $u=v$, we call e as "loop"

In Figure 1, V = {A,B,C,D} and E = {{A,B},{A,B},{A,C},{B,C},{B,D},{B,D},{C,D}}.

Here, E is a multiset.

If there are no loops and E is a set(no parallel edges), then G is a **simple graph**.

- u is **neighbor** of v if $\lbrace u,v\rbrace \in E$, edge $\lbrace u,v\rbrace$ is **incident** to u and v.
- **Degree** of vertex u is number of incident edges

![20221105110711](https://raw.githubusercontent.com/zxc2012/image/main/20221105110711.png)

In **directed graph**, each $e\in E$ defined as $(u,v)$.
- the **in-degree** of a vertex u is the number of edges from other vertices to u, and the **out-degree** of u is the number of edges from u to other vertices.

![20221105112539](https://raw.githubusercontent.com/zxc2012/image/main/20221105112539.png)

### Representation

- Adjacency matrices are true if there is a line going from node A to B and false otherwise
- Adjacency lists list out all the nodes connected to each node in our graph

    ![20221121170549](https://raw.githubusercontent.com/zxc2012/image/main/20221121170549.png)

DFS and BFS runtime with adjacency list: O(V + E) (creating marked array)

DFS and BFS runtime with adjacency matrix: O($V^2$)

DFS is worse for spindly graphs (Θ(V) memory to remember recursive calls)

BFS is worse for absurdly “bushy” graphs (In worst case, queue will require Θ(V) memory.)


### Paths, walks, cycles, tour

- Path: a sequence of edges $(v_1,v_2),(v_2,v_3),...,(v_{k-1},v_k)$
- Cycle: Path from $v_1$ to $v_{k-1}$, + edge $(v_{k-1},v_1)$
- Walk is sequence of edges with possible repeated vertex or edge
- Tour is walk that starts and ends at the same node.

### Connectivity

u and v are connected if there is a path between u and v

A **connected graph** is a graph where all pairs of vertices are
connected.

**Connected component**: maximal set of connected vertices.

### Complete Graph

$K_n$ complete graph on n vertices

every pair of (distinct) vertices u and v are connected by an edge $\lbrace u,v\rbrace$.

![20221105155349](https://raw.githubusercontent.com/zxc2012/image/main/20221105155349.png)

### Shortest Path

Dijkstra's algorithm /ˈdaɪkstrə/

```java
int dijkstra(){
    PQ.add(source, 0);
    While (!PQ.empty()){
        p = PQ.removeSmallest();
        If distTo[p] + w < distTo[q]{
            distTo[q] = distTo[p] + w; // relax
            edgeTo[q] = p;
            PQ.changePriority(q, distTo[q]);
        }
    }
}
```

Dijkstra’s is guaranteed to return a correct result if all edges are non-negative

Proof:

After relaxing all edges from source, let vertex v1 be the vertex with minimum weight(closest to the source) 

Claim: distTo[v1] is optimal, and thus future relaxations will fail
- distTo[p]         ≥ distTo[v1] for all p, therefore
- distTo[p] + w ≥ distTo[v1]

Runtime: 

- add: V, each costing O(log V) time.
- removeSmallest: V, each costing O(log V) time.
- changePriority: E, each costing O(log V) time.

Assuming E > V, this is just O(Elog V) for a connected graph

### DAG

#### Directed acyclic graph

Topological sort: order the vertices one after the other in such a way that each edge goes from an earlier vertex to a later vertex

A topological sort only exists if the graph is a DAG

**Property**: Every dag has at least one source and at least one sink(proof easy)

**Algorithm**: O(V+E) time Θ(V) space

1. process all of the edges and keep a count of
the number of incoming edges for each node
2. Find a source, output it, and delete it from the graph
3. The graph is still a DAG, and thus will still have a source vertex.
4. Repeat until the graph is empty.

#### Shortest path on DAG

Dijkstra may suffer from negative edges(dist to 5 is update earlier than 2)

![20221209223906](https://raw.githubusercontent.com/zxc2012/image/main/20221209223906.png)

Solution: Topological sort->Each vertex is visited only when all possible info about it has been used

**Algorithm**: O(V+E) time Θ(V) space

1. Visit vertices in topological order
2. On each visit, relax all outgoing edges

## Tree

A connected graph without a cycle

or: A connected graph with |V| −1 edges.

### BST

Binary search in ordered linked list

Move pointer to middle and flip left links

![20221128220141](https://raw.githubusercontent.com/zxc2012/image/main/20221128220141.png)

Binary Search Tree

![20221128220221](https://raw.githubusercontent.com/zxc2012/image/main/20221128220221.png)

For every node X in the tree:
- Every key in the left subtree is less than X's key
- Every key in the right subtree is greater than X's key

#### insert
```java
insert(BST T, Key ik) {
    if (T == null)
        return new BST(ik);
    if (ik ≺ T.key)
        T.left = insert(T.left, ik);
    else if (ik ≻ T.key)
        T.right = insert(T.right, ik);
    return T;
}
```

#### delete

Deletion with two Children(Hibbard)

If we want to delete k, move g or m upward

![20221128221020](https://raw.githubusercontent.com/zxc2012/image/main/20221128221020.png)

#### Implement Map

To represent maps, just have each BST node store key/value pairs

#### Tree Height

- Θ(log N) in the best case (Left: "bushy")
- Θ(N) in the worst case (Right: "spindly")
- Θ(log N) height if constructed via random inserts

![20221128222035](https://raw.githubusercontent.com/zxc2012/image/main/20221128222035.png)

#### BST Rotation

rotateLeft(G): Head->Left Child

![20221202112028](https://raw.githubusercontent.com/zxc2012/image/main/20221202112028.png)

rotateRight(P): Head->Right Child

![20221202112721](https://raw.githubusercontent.com/zxc2012/image/main/20221202112721.png)

Rotation:
- Can shorten (or lengthen) a tree
- Preserves search tree property

### BTree
#### Concept
Problem with BST: Adding new leaves at the bottom makes it imbalanced
-> Avoid new leaves by "overstuffing" the leaf nodes

![20221201211741](https://raw.githubusercontent.com/zxc2012/image/main/20221201211741.png)

Height is balanced, but leaf nodes can get too juicy

Solution: Set a limit L on the number of items, say L=3, move the left-middle

![20221201212635](https://raw.githubusercontent.com/zxc2012/image/main/20221201212635.png)

B(balanced/bushy)-trees of order L=3 are also called a 2-3-4(number of children) tree or a 2-4 tree

#### B-Tree Runtime Analysis

Height: 
- Largest possible height is all non-leaf nodes have 1 item ($log_2n$)
- Smallest possible height is all nodes have L items ($log_{l+1}n$)
- Overall height is therefore Θ(log n) 

Contains:
- Worst case number of nodes to inspect: H + 1
- Worst case number of items to inspect per node: L
- Overall runtime: O(HL) = O(log n)

Add:
- Worst case number of nodes to inspect: H + 1
- Worst case number of items to inspect per node: L
- Worst case number of split operations: H + 1
- Overall runtime: O(HL) = O(log n)

### Red-Black Trees

Representing a 2-3 Tree as a BST
- Binary search trees: Can balance using rotation
- 2-3 Tree: Balanced by construction

Solution: Create "glue"(red) links with the smaller item off to the left

![20221202113356](https://raw.githubusercontent.com/zxc2012/image/main/20221202113356.png)

Left-Leaning Red Black Binary Search Tree (LLRB)

There is a 1-1 correspondence between an LLRB and an equivalent 2-3 tree

![20221202113510](https://raw.githubusercontent.com/zxc2012/image/main/20221202113510.png)

```java
private class Node {
    private Key key;           // key
    private Value val;         // associated data
    private Node left, right;  // links to left and right subtrees
    private boolean color;     // color of parent link
    private int size;          // subtree count

    public Node(Key key, Value val, boolean color, int size) {
        this.key = key;
        this.val = val;
        this.color = color;
        this.size = size;
    }
}
```

#### LLRB Height

LLRB has no more than ~2x the height of its 2-3 tree: O(log n)

#### Insertion

Use red link

![20221202114204](https://raw.githubusercontent.com/zxc2012/image/main/20221202114204.png)

#### Insertion on the Right

If there is a right leaning "3-node", Rotate left the appropriate node to fix

![20221202114424](https://raw.githubusercontent.com/zxc2012/image/main/20221202114424.png)

```java
private Node rotateLeft(Node h) {
    assert (h != null) && isRed(h.right);
    Node x = h.right;
    h.right = x.left;
    x.left = h;
    x.color = h.color;
    h.color = RED;
    x.size = h.size;
    h.size = size(h.left) + size(h.right) + 1;
    return x;
}
```

#### Double Insertion on the Left

If there are two consecutive left links, rotate right the appropriate node to fix

![20221202115012](https://raw.githubusercontent.com/zxc2012/image/main/20221202115012.png)

```java
private Node rotateRight(Node h) {
    assert (h != null) && isRed(h.left);
    Node x = h.left;
    h.left = x.right;
    x.right = h;
    x.color = h.color;
    h.color = RED;
    x.size = h.size;
    h.size = size(h.left) + size(h.right) + 1;
    return x;
}
```

#### Splitting 4-Nodes

If there are any nodes with two red children, color flip

![20221202115231](https://raw.githubusercontent.com/zxc2012/image/main/20221202115231.png)

```java
private void flipColors(Node h) {
    h.color = !h.color;
    h.left.color = !h.left.color;
    h.right.color = !h.right.color;
}
```

#### Cascading operations

It is possible that a rotation or flip operation will cause an additional violation that needs fixing

![20221202115843](https://raw.githubusercontent.com/zxc2012/image/main/20221202115843.png)

Wrapping it up

```java
private Node put(Node h, Key key, Value val) {
    if (h == null) return new Node(key, val, RED, 1);

    int cmp = key.compareTo(h.key);
    if      (cmp < 0) h.left  = put(h.left,  key, val);
    else if (cmp > 0) h.right = put(h.right, key, val);
    else              h.val   = val;

    // fix-up any right-leaning links
    if (isRed(h.right) && !isRed(h.left))      h = rotateLeft(h);
    if (isRed(h.left)  &&  isRed(h.left.left)) h = rotateRight(h);
    if (isRed(h.left)  &&  isRed(h.right))     flipColors(h);
    h.size = size(h.left) + size(h.right) + 1;

    Balance(); // Cascading operations
    return h;
}
```

#### LLRB Runtime

- Contains: O(log n)
- Insert:
    - O(log n) to add the new node
    - O(log n) rotation and color flip operations per insert

### Minimum Spanning Trees

Input: An undirected graph G = (V, E), edge weights $w_e$

Output: A tree $T = (V, E')$, with $E_0 \subset E$, that minimizes

$$weight(T) = \sum_{e\in E'}w_e$$

![20221105161941](https://raw.githubusercontent.com/zxc2012/image/main/20221105161941.png)

**Cut property**

A *cut* is any partition of V into two groups, S and V −S

A *crossing edge* is an edge which connects a node from S to a node from the V-S

Claim: Given any cut, minimum weight crossing edge is in the MST

Proof: 

Suppose a minimum spanning tree $T$ doesn't contain e, then there must be some other edge $e'$ across the cut (S, V −S)

if we remove $e'$ and add $e$,  $T' = T \lbrace e\rbrace − \lbrace e'\rbrace$, then T' must be connected.

And it has the same number of edges as T; so it is also a tree.

but $weight(T')\leq weight(T)$

![20221105164746](https://raw.githubusercontent.com/zxc2012/image/main/20221105164746.png)

#### Kruskal's Algorithm

```cpp
for ( u : V)
    makeset(u); //create a singleton set containing just u
X = {};
Sort the edges E by weight
for all edges {u, v} in E, in increasing order of weight:
    if (find(u)!= find(v)) // to which set does u and v belong
        add edge {u, v} to X
        union(u, v);
```

#### Prim's Algorithm

