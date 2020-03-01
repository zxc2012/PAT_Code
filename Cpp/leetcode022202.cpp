#include<bits/stdc++.h>
using namespace std;
class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        num=n;d=discount;
        int m=products.size();
        for(int i=0;i<m;++i){
            p[products[i]]=prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        step++;double sum=0;
        int m=product.size();
        for(int i=0;i<m;++i){
            sum+=p[product[i]]*amount[i];
        }
        if(step%num==0)sum*=(1-d/100.0)*1.0;
        return sum;
    }
private:
    int num=0,d=0,step=0,p[200]={0};
};
int main(){
    Solution s;
    return 0;
}