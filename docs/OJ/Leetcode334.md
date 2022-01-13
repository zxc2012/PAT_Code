# Leetcode 334 Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

## Analysis

很像Longest Increasing Subsequence，但限定了3个元素，可以把lower_bound 换成单独元素->O(1)

从方法上看，都是采用贪心策略，让前面的元素尽可能小

## Solution

```cpp
bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    int first = nums[0],second = INT_MAX;
    for(int &p:nums){
        if(p>second) return true;
        else if(p>first) second = p;
        else first = p;
    }
    return false;
}
```