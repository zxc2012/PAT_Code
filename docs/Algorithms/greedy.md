# Huffman Tree
## Introduction
- Fixed-length coding: Information Entropy(en- tropical`turn`混乱)
- Variable-length coding: Prefix-Free code (no codeword is a prefix of a codework of another symbol)

## Proof
### Theorem
- T: a tree for some prefix encoding A and some probability distribution p over the symbols.
- x and y: two leaves
- T': the tree obtained by swapping x and y in T.

*Then*

$E_p(T')-E_p(T)=(p(x)-p(y))(depth(y,T)-depth(x,T))$


### Lemma
`something received or taken (di-:both side)`

**An optimal tree**
two symbols with least probabilities are sibling leaves in the lowest level.
*Easy*
### Correctness proof
- n=2 obvious
- n>2

Consider an alphabet A of n-1 letters.(except the two least probabilities leaves which parent is z) 

Let T be an optimum tree for A

Let A'=A+{x,y}-z,T':adding x,y as children of z.

$H'$:optimum tree for A' 

$H$:removing x,y from H;

*Then*
$E_p(T)<=E_p(H)$

$E_p(T')=E_p(T)+p(x)+p(y)<=E_p(H')$

$E_p(T')>=E_p(H')$

so $E_p(T')=E_p(H')$
# Tree's