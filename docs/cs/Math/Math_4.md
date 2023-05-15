# 4 Numrical Analysis
## Evaluating a polynomial
Direct form:O($n^2$)
>$P(x)=a_0+a_1x+a_2x^2+...+a_nx^n$

Horner's method:O(n)
>$P(x)=a_0+x(a_1+x(a_2+x*(...(a_{n-1}+a_nx)))$

Example:求二进制幂O(n)->O($log_2n$)
>$a^n=a^{p(2)}$$=a^{b_m2^m+...+b_i2^i+b_0}$

>$a^{2p+b_i}=a^{2p}*a$ or $a^{2p}$

## Errors
Assume that r is the root of function f(x)=0.

**Forward Error**:$|r-x_a|$

**Backward Error**:$f(x_a)$

![lk](https://raw.githubusercontent.com/zxc2012/image/main/20200927222415895.png)

##  Solving Equations
*Newton's Method*

$x_0=initial\ guess$

$x_{i+1}=x_i-\frac{f(x_i)}{f'(x_i)}$

## Convex Optimization

Convex combination: $(x,y)\rightarrow\{\alpha x + \beta y|\alpha + \beta =1, \alpha,\beta \geq 0\}$

Convex set S: $(x1, . . . , xk) \in S$, then convex combination of the points x1, . . . , xk should $\in$ S.

A function f : $R^n \rightarrow R$ is convex if $\forall x, y$ and $\forall \alpha \in [0, 1]$

$$f(\alpha x + (1-\alpha) y) \leq \alpha f(x) + (1-\alpha) f(y)$$

![20230512172643](https://raw.githubusercontent.com/zxc2012/image/main/20230512172643.png)