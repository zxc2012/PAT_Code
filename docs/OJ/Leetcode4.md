## Leetcode 4 Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

![20210904113642](https://raw.githubusercontent.com/zxc2012/image/main/20210904113642.png)
```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n=nums1.size(),m=nums2.size();
    if(n>m)return findMedianSortedArrays(nums2,nums1);
    int k=m+n;
    int l=0,r=n;
    while(l<r){
        int mid=l+r>>1;
        int m2=(k+1>>1)-mid;
        if(nums1[mid]<nums2[m2-1])l=mid+1;
        else r=mid;
    }
    int m2=(k+1>>1)-l;
    int left=m2==0?nums1[l-1]:l==0?nums2[m2-1]:max(nums1[l-1],nums2[m2-1]);
    if(k%2==0){
        int right=m2==m?nums1[l]:l==n?nums2[m2]:min(nums1[l],nums2[m2]);
        return (left+right)/2.0;
    }
    else return left;
}
```