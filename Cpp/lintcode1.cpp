#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deduplication(vector<int> &nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int n=nums.size(), index=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]) 
                nums[++index]=nums[i];
        }
        return index+1;
    }
};
int main(){
	Solution s;
	vector<int> nums={1,3,1,4,4,2};
	int n=nums.size();
	printf("count:%d\n",s.deduplication(nums));
	for(int i=0;i<n;++i)
	printf("%d ",nums[i]);
	return 0;
}
