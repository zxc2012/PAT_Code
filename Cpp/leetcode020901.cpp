#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int flag=0;
        for(int i=0;i<n;++i){
            auto a=upper_bound(arr.begin()+1,arr.end(),2*arr[i]);
            if(arr.back()<2*arr[i])break;
            if(arr[i]==0)if(arr[i+1]==0){flag=1;break;}
            else continue;
            //printf("%d\n",*(a-1));
            if(*(a-1)==2*arr[i]){flag=1;break;}
        }
        return flag;
    }
};
int main(){
    Solution s;
    vector<int> v={10,2,5,3};
    printf("%d",s.checkIfExist(v));
    return 0;
}
