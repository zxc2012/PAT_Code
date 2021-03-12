#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> arr(2);
        vector<int> p;
        int n=S.size();
        int index=0;
        for(int i=0;i<n;++i){
            arr[0]=x=stoi(S.substr(0,i+1));
            for(int j=1;j+i<n;++j){
                arr[1]=y=stoi(S.substr(i+1,i+j+1));
                index=i+j+1;
                while(index<n){
                	int temp=y;
                    y+=x;
                    x=temp;
                    string m=to_string(y);
                    string mm=S.substr(index,index+m.size());
                    cout<<mm;
                    printf("%s %s\n",m.c_str(),S.substr(index,index+m.size()).c_str());
                    if(m!=S.substr(index,index+m.size()))break;
                    index+=m.size();
                    arr.push_back(y);
                }
                if(index>=n&&arr.size()>2)return arr;
            }
        }
        return p;
    }
private:
    int x,y;
};
int main(){
	Solution s;
	string ss="123456579";
	s.splitIntoFibonacci(ss);
}
