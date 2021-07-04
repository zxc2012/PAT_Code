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

##  Set Mismatch

[题目链接](https://leetcode-cn.com/problems/set-mismatch/)

a set of integers 1 to n but got repetition of one number and loss of another number,e.g. [1,2,2,4]

find the duplicate and the missing.

**在后面添加1 to n，构建3个duplicate和1个missing,然后在数量上做文章**

```cpp
vector<int> findErrorNums(vector<int>& nums) {
    int sum=0,num1=0,num2=0;
    int n=nums.size();
    vector<int> result(2);
    for(int i=0;i<n;++i){
        sum^=nums[i];
        sum^=(i+1);
    }
    int low=sum&(-sum);
    for(int i=0;i<n;++i){
        if((nums[i]&low)==0)num1^=nums[i];
        else num2^=nums[i];
        if(((i+1)&low)==0)num1^=(i+1);
        else num2^=(i+1);
    }
    for(int i=0;i<n;++i){
        if(nums[i]==num1||nums[i]==num2){
            result[0]=nums[i];
            result[1]=nums[i]==num1?num2:num1;
            break;
        }
    }
    return result;
}
```