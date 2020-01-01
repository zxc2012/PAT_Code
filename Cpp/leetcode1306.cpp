#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int x=arr.size();
        if(find(arr.begin(),arr.end(),0)==arr.end()){
            printf("pre");return 0;
        }
        return dfs(start,arr,x,start,0);
    }
private:
    bool dfs(int s,vector<int>& arr,int& length,int& start,int& flag){
        if(arr[s]==0){printf("find");return 1;}
        else if(s==start&&flag=1){printf("duply");return 0;}
        else{
            flag=1;
            return s+arr[s]<length&&dfs(s+arr[s],arr,length,start,flag)||s+arr[s]>=0&&dfs(s-arr[s],arr,length,start,flag);
        }
    }
};
int main(){
    int arr[7] ={4,2,3,0,3,1,2}, start = 5;
    vector<int>ae(arr,arr+7);
    Solution s;
    printf("%d",s.canReach(ae,start));
    return 0;
}