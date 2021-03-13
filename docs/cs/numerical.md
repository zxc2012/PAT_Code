# Numrical Analysis Summary
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
![lk](https://img-blog.csdnimg.cn/20200927222415895.png#pic_center)
##  Solving Equations
*Newton's Method*

$x_0=initial\ guess$

$x_{i+1}=x_i-\frac{f(x_i)}{f'(x_i)}$