## 同向指针
### Move zeros
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:
Input: nums = [0, 1, 0, 3, 12],
Output: [1, 3, 12, 0, 0].
```cpp
void moveZeroes(vector<int> &nums) {
    int n=nums.size();
    int i=-1;
    for(int j=0;j<n;++j){
        if(nums[j]!=0)nums[++i]=nums[j];
    }
    for(int j=i+1;j<n;++j)nums[j]=0;
}
```
## 相向指针
### Valid Palindrome

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

```cpp
bool isPalindrome(string &s) {
    int n=s.size();
    int i=0,j=n-1;
    while(i<=j-1){
        while(!isalnum(s[i]))++i;
        s[i]=tolower(s[i]);
        while(!isalnum(s[j]))--j;
        s[j]=tolower(s[j]);
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
```
