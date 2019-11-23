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