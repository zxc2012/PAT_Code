# 3 Probability
## Random Variable

A random variable X on a sample space Ω is a function X : Ω → R
that assigns to each sample point $ω \in Ω$ a real number $X(ω)$.

Let a be any number in the range of a random variable X. Then $X(ω) = a$ is an event in the sample space. We usually abbreivate this event to "X = a".

The **distribution** of a discrete random variable X is the collection of values
$\{(a,P[X = a])\}$, where a $\in$ the set of all possible values taken by X

### Distribution

#### Bernoulli Distribution(aka 0-1 distribution)

$$
\begin{aligned}
P[X=i]=
\begin{cases}
        p, & i=1 \\
        1-p, & i=0 
\end{cases} \\
    E(X)=p \\	
    Var(X)=p(1-p)
\end{aligned}
$$

We say that X is distributed as a Bernoulli random variable with parameter p

X ∼ Bernoulli(p)

#### Binomial Distribution

n times Bernoulli experiments

$$\begin{aligned}
P[X=i] =(
\begin{matrix}
n\\i
\end{matrix}
)p^i(1-p)^{n-i}
\qquad \text{i =0,1,...,n}\\
E(X) = np \\
Var(X) = np(1-p)
\end{aligned}
$$

X ∼ Binomial(n, p)

#### Geometric Distribution

$$\begin{aligned}
P[X = i]= (1− p)^{i-1}p
\qquad \text{i = 1,2,3,..} \\
E(X) = \frac{1}{p} \\
Var(X) = \frac{1-p}{p^2}
\end{aligned}
$$

X ∼ Geometric(p)

#### Poisson Distribution

$$\begin{aligned}
P[X = i]= \frac{\lambda^i}{i!}e^{-\lambda}
\qquad \text{i=0,1,2,...} \\
E(X) = Var(X) = \lambda
\end{aligned}
$$

## Continuous Variable

A probability density function(p.d.f.) for a real-valued random variable X is a function f : R → R satisfying

1. $f(x) \geq 0$ for all $x \in R$.
2. $\int_{-\infty}^{\infty}f(x)dx = 1$

Then the distribution of X is given by $P[a\leq x\leq b] = \int_a^b f(x)dx$

cumulative distribution function(c.d.f.) $F(x) = \int_{-\infty}^xf(z)dz$

### Distribution
#### Uniform distribution

$f(x) = \begin{cases}
\frac1{b-a}, & a\leq x\leq b \\
0, & other
\end{cases}
$

X ∼ U(a,b)

#### Exponential Distribution

For $\lambda > 0$, X ∼ Exp(λ)

$f(x) = \begin{cases}
\lambda e^{-\lambda x}, & x\geq 0 \\
0, & other
\end{cases}
$