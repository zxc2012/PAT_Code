#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void push(int value) {
        Data.push(value);
        if(Min.empty()){
            Min.push(value);
        }
        if(Min.top() > value){
            Min.push(value);
        }
    }
    void pop() {
        if(Data.top() == Min.top()){
            Min.pop();
        }
        Data.pop();
    }
    int top() {
        return Data.top();
    }
    int min() {
        return Min.top();
    }
private:
    stack<int> Data;            //数据栈
    stack<int> Min;                //最小栈
};

int main(){
    Solution s;
    s.push(2);
    s.push(3);
    s.push(2);
    s.pop();
    printf("%d\n",s.min());
    //printf("%d\n",s.top());
    s.pop();
    return 0;
}