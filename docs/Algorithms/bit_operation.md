# 位运算总结
## 二进制中1的个数
[题目链接](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)
### 每位遍历O(n)
```cpp
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int flag=1,sum=0;
         for(int i=0;i<32;++i){
             sum+=flag&n?1:0;
             flag<<=1;
         }
         return sum;
     }
};
```
### 只遍历1的个数O(m)
```cpp
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int sum=0;
         while(n!=0){
             n=n&(n-1);
             sum++;
         }
         return sum;
     }
};
```