class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        auto cmp = [&](pair<int,int> &a,pair<int,int> &b)->bool{
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int i=0;i<min(k,m);++i)pq.push({0,i});
        vector<vector<int>> ans;
        while(!pq.empty()&&k--){
            pair<int,int> elem = pq.top();
            ans.push_back(vector<int>({nums1[elem.first],nums2[elem.second]}));
            pq.pop();
            if(elem.first+1<n) pq.push({elem.first+1,elem.second});
        }
        return ans;
    }
};