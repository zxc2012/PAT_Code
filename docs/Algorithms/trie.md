# String Matching 
## Introduction

Search for a string (pattern) in a large body of text
- T[0...n − 1]: The text (or haystack) being searched within
- P[0...m − 1]: The pattern (or needle) being searched for
- Return smallest i such that $P[j] = T[i+j]$ for $0\leq j\leq m-1$ 

This is the first **occurrence** of P in T

Brute Force: Θ(mn)
 
## Knuth-Morris-Pratt Algorithm

When a mismatch occurs, the most we can shift the pattern: the largest prefix of P[0...j] that is a suffix of P[1...j]

### KMP Failure Array

The failure array : fail[j] is defined as the length of the largest prefix of P[0...j] that is also a suffix of P[1...j]
- fail[0] = 0
- If a mismatch occurs at P[j] $\neq$ T[i] we set j = fail[j − 1]

![20230531170333](https://raw.githubusercontent.com/zxc2012/image/main/20230531170333.png)

Construct the FailArray: almost same as KMP, pattern becomes part of P

### Algorithm

- Runtime: Θ(m + n)
- Space: Θ(m + n)

```cpp
int KMP(){
    //T: String of length n (text), P: String of length m (pattern)
    // Construct FailArray, but each case add F[i]
    int i = 1, j = 0;
    while(i < m){
        if(p[j] == p[i]){
            fail[i] = j + 1; // 0...j
            ++i;
            ++j;
        }
        else{
            if(j > 0)j = fail[j-1];
            else{
                fail[i] = 0;
                ++i;
            } 
        }
    }
    // KMP 
    i = 0, j = 0;
    while(i < n){
        if(p[j] == t[i]){
            ++j;
            ++i;
            if(j == m){
                j = fail[j - 1];
                result.push_back(i - m); // starting point
            }
        }
        else{
            if(j > 0)j = fail[j - 1];
            else ++i;
        }
    }
}
```

## Regular Expression
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​

'*' Matches zero or more of the preceding element.

### Solution:

The matching should cover the entire input string (not partial).

Iterate Two strings, match one by one

- case 0: 一般情况judge(str[i-1],pattern[j-1])
    - dp[i][j]=dp[i-1][j-1]
- case 1: pattern[j-1]=='*':
    
  两种小情况:
  
  (1)not use preceding char 
  
  (2)preceding char use multiple times

    - dp[i][j]=dp[i][j-2]||judge(str[i-1],pattern[j-2]&&dp[i-1][j])

### Code
```cpp
class Solution {
public:
    bool match(string s, string p) {
        int n=p.size();
        int m=s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=2;i<=n;++i){
            if(p[i-1]=='*')dp[0][i]=dp[0][i-2];
        }
        for(int i=1;i<=m;++i)for(int j=1;j<=n;++j){
            if(judge(s[i-1],p[j-1]))
                dp[i][j]=dp[i-1][j-1];
            else if(p[j-1]=='*')
                dp[i][j]=dp[i][j-2]||judge(s[i-1],p[j-2])&&dp[i-1][j];
        }
        return dp[m][n];
    }
private:
    bool judge(char a,char b){return a==b||b=='.';}
};
```

## Regular Expressions
<table>
<tr>
    <th>Category</th>
    <th>Pattern</th>
    <th >Matches</th>
</tr>
<tr>
    <td rowspan="6">Disjuncitons</td>
    <td>/[A-Z|a-z]/</td>
    <td>An upper/lower case letter</td>
</tr>
<tr>
    <td>/[0-9]/</td>
    <td>A single digit</td>
</tr>
<tr>
    <td>/[^A-Z]/</td>
    <td>Negations</td>
</tr>
<tr>
    <td>/\d/</td>
    <td>any digit</td>
</tr>
<tr>
    <td>/\D/</td>
    <td>any non-digit</td>
</tr>
<tr>
    <td>/./</td>
    <td>Any character except for newline</td>
</tr>
<tr>
    <td rowspan="2">Anchors</td>
    <td>/^/</td>
    <td>Start of Input</td>
</tr>
<tr>
    <td>/$/</td>
    <td>End of Input</td>
</tr>
<tr>
    <td rowspan="5">Frequencies</td>
    <td>/?/</td>
    <td>Optional(one or none)</td>
</tr>
<tr>
    <td>/*/</td>
    <td>zero or more</td>
</tr>
<tr>
    <td>/+/</td>
    <td>one or more</td>
</tr>
<tr>
    <td>/&#123;m&#125;/</td>
    <td>m repetitions</td>
</tr>
<tr>
    <td>/&#123;m,n&#125;/</td>
    <td>m to n repetitions</td>
</tr>
<tr>
    <td>Others</td>
    <td>/()/</td>
    <td>capture group</td>
</tr>
</table>
