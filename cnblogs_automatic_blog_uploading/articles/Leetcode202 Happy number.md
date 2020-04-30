## Description
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.
## 
>Input: 19

>Output: true

>Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

## Analysis
`判断环的两大方法`

### Hashset
```cpp
class Solution {
public:
    bool isHappy(int n) {
        while(n!=1){
            n=process(n);
            if(a[n]==1)return 0;
            a[n]=1;
        }
        return 1;
    }
private:
    int process(int x){
        int sum=0;
        while(x!=0){
            int u=x%10;
            sum+=u*u;
            x/=10;
        }
        return sum;
    }
    int a[50000];
};
```

### 龟兔赛跑法
![](https://assets.leetcode-cn.com/solution-static/202/1.jpg)
*设定两个指针，一快一慢，快的一次走2步，慢的一次走1步*
## Code

```cpp
class Solution {
public:
    bool isHappy(int n) {
        int a=n,b=n;
        while(a!=1){
            a=process(a);
            a=process(a);
            b=process(b);
            if(a==b)break;
        }
        return a==1;
    }
private:
    int process(int x){
        int sum=0;
        while(x!=0){
            int u=x%10;
            sum+=u*u;
            x/=10;
        }
        return sum;
    }
};
```