#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
        double x;
        if(equal(base,0.0))x=0;
        if(exponent==0)x=1;
        else if(exponent<0)x=p(base,-exponent);
        else x=p(base,exponent);
        return x;
    }
 private:
    double p(double base,int e){
        double x;
        if(e==0)x=1;
        else if(e%2==0)x=p(base,e>>1);
        else x=base*p(base,(e-1)>>1);
        return x;
    }
    bool equal(double a,double b){
        if(abs(a-b)<1e-9)return 1;
        else return 0;
    }
};
int main(){
    Solution s;

    return 0;
}
