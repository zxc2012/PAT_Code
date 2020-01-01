#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>v;
        if(n%2==0){
            for(int i=1;2*i<=n;++i){
                v.push_back(i);v.push_back(-i);
            }
        }else{
            v.push_back(0);
            for(int i=1;2*i<=n-1;++i){
                v.push_back(i);v.push_back(-i);
            }
        }
        return v; 
    }
};
int main(){

    return 0;
}