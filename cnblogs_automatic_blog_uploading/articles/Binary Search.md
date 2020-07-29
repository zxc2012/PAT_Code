## 二分查找
在闭区间查找[begin,end],注意对找不到的处理
```cpp
int binary_find(vector<int>& nums, int target){
    int l=0,r=nums.size()-1;//Notice
    while(l<r){
        int mid=l+(r-l)>>1;
        if(nums[mid]==target)return mid;
        else if(nums[mid]>target)r=mid-1;
        else l=mid+1;
    }
    return nums[l]==target?l:-1;
}
```
## 二分搜索
1. 在[begin,end)查找,故格外注意边界
2. 满足条件时右不变,不满足时左加一
3. 注意变式如求上界(注释部分)
```cpp
int upper_bound(vector<int>& nums, int target){
    int l=0,n=nums.size();//Notice
    int r=n;
    while(l<r){
        int mid=l+(r-l)>>1;
        if(nums[mid]>target)r=mid;
        else l=mid+1;
    }
    if(r==n)return -1;
    if(nums[l]!=target)return -1;
    else return l;
    /*
    if(l==0)return -1;
    if(nums[l-1]!=target)return -1;
    else return l-1;    
    */
}
int lower_bound(vector<int>& nums, int target){
    int l=0,n=nums.size();//Notice
    int r=n;
    while(l<r){
        int mid=l+(r-l)>>1;
        if(nums[mid]>=target)r=mid;
        else l=mid+1;
    }
    if(r==n)return -1;
    if(nums[l]!=target)return -1;
    else return l;
}
```