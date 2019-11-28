## 贪心
- 二分法upper_bound,lower_bound的运用
- PAT题，利用次序
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
- 数学形式题注意对数字的直接利用，少用字符串特性

1.素数
##### 算术基本定理:若$a\in Z$,$a\gt 1$,则有$a=p_1p_2\cdots p_n$,其中$p_i$为素数
>证明：
假定定理对所有小于a的正整数均成立
若a为素数,则结论显然成立
若a为合数,$a=bc$,其中$1\lt b,c\lt a$
由归纳假设$b=p_1p_2\cdots p_k,c=p_{k+1}p_{k+2}\cdots p_n$
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
- `陷阱:1的特殊处理(极易错)`
```cpp
bool judge(int x){
	if(x<2)return 0;
    for(int i=2;i<=sqrt(x);++i){
        if(x%i==0)return 0;
    }
    return 1;
}
```