<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML"></script>
<script type="text/x-mathjax-config">
    MathJax.Hub.Config({ tex2jax: {inlineMath: [['$', '$']]}, messageStyle: "none" });
</script>
## 暴力求解/数学问题
1.素数
##### 算术基本定理:若$a\in Z$,$a\gt 1$,则有$a=p_1p_2\cdots p_n$,其中$p_i$为素数
>##### 证明:假定定理对所有小于a的正整数均成立 若a为素数,则结论显然成立 若a为合数,$a=bc$,其中$1\lt b,c\lt a$由归纳假设$b=p_1p_2\cdots p_k,c=p_{k+1}p_{k+2}\cdots p_n$
```cpp
for(int i = 2; i <= n; i++)
{
	if(!vis[i])
	prime[cnt++] = i;
	for(int j = 0; j<cnt && i*prime[j]<=n; j++)
	{
		vis[i*prime[j]] = 1;
		if(i % prime[j] == 0) break;
	}
}
```
##### 判断
`陷阱:1的特殊处理(极易错)`
```cpp
bool judge(int x){
	if(x<2)return 0;
    for(int i=2;i<=sqrt(x);++i){//9
        if(x%i==0)return 0;
    }
    return 1;
}
```
2.gcd
```cpp
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}//原来a>b现调换
```
3.数据类型范围
<table>
<thead>
<tr>
<th>数据类型</th>
<th>用10表示</th>
<th>用2表示</th>
</tr>
</thead>
<tbody>
<tr>
<td>unsigned int</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%204%C3%9710%5E%7B9%7D" alt="0, 4×10^{9}" mathimg="1"0, 4×10^9></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%202%5E%7B32%7D-1" alt="0, 2^{32}-1" mathimg="1"></td>
</tr>
<tr>
<td>int</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%C3%9710%5E%7B9%7D%2C%202%C3%9710%5E%7B9%7D" alt="-2×10^{9}, 2×10^{9}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%5E%7B31%7D%2C%202%5E%7B31%7D-1" alt="-2^{31}, 2^{31}-1" mathimg="1"></td>
</tr>
<tr>
<td>unsigned long</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%204%C3%9710%5E%7B9%7D" alt="0, 4×10^{9}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%202%5E%7B32%7D-1" alt="0, 2^{32}-1" mathimg="1"></td>
</tr>
<tr>
<td>long</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%C3%9710%5E%7B10%7D%2C%202%C3%9710%5E%7B10%7D" alt="-2×10^{10}, 2×10^{10}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%5E%7B31%7D%2C%202%5E%7B31%7D-1" alt="-2^{31}, 2^{31}-1" mathimg="1"></td>
</tr>
<tr>
<td>long long</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%209%C3%9710%5E%7B18%7D" alt="0, 9×10^{18}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%5E%7B63%7D%2C%202%5E%7B63%7D-1" alt="-2^{63}, 2^{63}-1" mathimg="1"></td>
</tr>
<tr>
<td>unsigned long long</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%2010%5E%7B19%7D" alt="0, 10^{19}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=0%2C%202%5E%7B64%7D-1" alt="0, 2^{64}-1" mathimg="1"></td>
</tr>
</tbody>
</table>
<table>
<thead>
<tr>
<th>数据类型</th>
<th>比特位数</th>
<th>有效数字</th>
<th>用10表示</th>
<th>用2表示</th>
</tr>
</thead>
<tbody>
<tr>
<td>float</td>
<td>32</td>
<td>6~7</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-3.4*10%5E%7B38%7D%EF%BD%9E%2B3.4*10%5E%7B38%7D" alt="-3.4*10^{38}～+3.4*10^{38}" mathimg="1"></td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-2%5E%7B128%7D%20~%20%2B2%5E%7B128%7D" alt="-2^{128} ~ +2^{128}" mathimg="1"></td>
</tr>
<tr>
<td>double</td>
<td>64</td>
<td>15~16</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-1.7*10%5E%7B-308%7D~1.7*10%5E%7B308%7D" alt="-1.7*10^{-308}~1.7*10^{308}" mathimg="1"></td>
<td>——</td>
</tr>
<tr>
<td>long double</td>
<td>128</td>
<td>18~19</td>
<td><img class="math-inline" src="https://math.jianshu.com/math?formula=-1.2*10%5E%7B-4932%7D~1.2*10%5E%7B4932%7D" alt="-1.2*10^{-4932}~1.2*10^{4932}" mathimg="1"></td>
<td>——</td>
</tr>
</tbody>
</table>

---
## 求解技巧
`思路:遍历范围内全部数字,依据首+尾/首+间隔遍历`

1.二分法upper_bound,lower_bound的运用

2.PAT题，利用次序
```cpp
for (int i = 0; i < len; i++) {
	if (s[i] == 'T')countt++;
}
for (int i = 0; i < len; i++) {
	if (s[i] == 'P')countp++;
	if (s[i] == 'T')countt--;
	if (s[i] == 'A')result = (result + (countp * countt) % 1000000007) % 1000000007;
}
```
3.数学形式题注意对数字的直接利用，少用字符串特性