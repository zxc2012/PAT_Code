## Description
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.


[Problem](https://leetcode-cn.com/problems/min-stack)

Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
## 易错点
注意考虑记录指针index永远指向当前元素/下一元素

## Code
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(s.empty())mini[++index]=x;
        else mini[++index]=min(mini[index],x);
        s.push(x);
    }
    
    void pop() {
        index--;
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini[index];
    }
private:
    stack<int> s;
    int mini[50000];
    int index=-1;
};
```