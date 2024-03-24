# 1 Modular Arithmetic
## Divisibility
### Definition
Let $x,y\in Z$ with $x\neq0$
We say that a divides b
a|b, if there exists some $k\in Z$ such that $b = ak$.

### Theorem
Proof Easy

1. If $a|b$ and $a|c$ then $a|(b+c)$
2. If $a|b$ then $a|bc$
3. If $a|b$ and $b|c$ then $a|c$ (**transitivity**)

**Corollary** 

Let $a, b, c \in Z$. If a|b and a|c, then a|mb+nc for any $m, n \in Z$

## Modular Arithmetic
### Definition

Let $x,y\in Z$,$m\in N^{+}$

we say x is congruent to y modulo m 

$x\equiv y\pmod m$ if and only if $m|(x-y)$

Notation: $x\equiv y\pmod m$ or $mod(x,m)$

**Claim** 

$x\equiv y\pmod m$ if and only if $x$ and $y$ have the same remainder when divided by m (Proof easy)

29 (mod 12) ≡ 5

13 (mod 5) ≡ 3.

### Lemma

if $a\equiv b\pmod m$, $c\equiv d\pmod m$,then

1. $a+c\equiv b+d\pmod m$

2. $ac\equiv bd\pmod m$

Solution:

1. $a\equiv b\pmod m$ and $c\equiv d\pmod m$

$\Rightarrow m|(a-b)$ and $m|(c-d)$

$\Rightarrow m|(a-b+c-d)$

$\Rightarrow m|(a+c-(b+d))$

$\Rightarrow a+c\equiv b+d\pmod m$

2. $m|(a-b)$ and $m|(c-d)$

$\Rightarrow m|ac-bc$ and $m|bc-bd$

$\Rightarrow m|ac-bd$

$\Rightarrow ac\equiv bd \pmod m$

### Theorem

1. If $d|x$ and $d|y$, then $d|mod(x,y)$

    Proof:

    $$mod(x,y)\Rightarrow y|x-mod(x,y)$$

    $$\because d|y$$

    $$\therefore d|x-mod(x,y)$$

    $$\therefore d|mod(x,y)$$

2. If $d|y$ and $d|mod(x,y)$, then $d|x$

    Similar

3. GCD Mod Corollary: $gcd(x,y)=gcd(y,mod(x,y))$

    x and y have same set of common divisors as x and mod (x,y) by Lemma.

    Same common divisors $\Rightarrow$ largest is the same.