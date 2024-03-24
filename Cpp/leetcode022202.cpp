#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        v.resize(n);
        for(vector &p:v[s])v[p[0]].push_back(p[1]);
        time=t,tar=target;
        return dfs(1);
    }
private:
    vector<vector<int>>v;
    int time,tar;
    double& dfs(double& m,int s,int l){
        int n=v[s].size();int x;
        if(l<=time&&s==tar)return m;
        for(int &p:v[s])if(x=dfs(m/n,p,++l)){break;return x;}
        return 0;
    }
};
int main(){
    Solution s;
    return 0;
}