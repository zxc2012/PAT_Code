# Discrete Structure 2--Graph
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

## Tree

A connected graph without a cycle

or: A connected graph with |V| −1 edges.

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

/ˈdaɪkstrə/