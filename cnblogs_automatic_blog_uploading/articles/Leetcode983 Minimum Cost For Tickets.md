## Description
[Problem](https://leetcode-cn.com/problems/minimum-cost-for-tickets)

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.

## Sample
### Sample1 
>Input: days = [1,4,6,7,8,20], costs = [2,7,15]

>Output: 11

Explanation:

For example, here is one way to buy passes that lets you travel your travel plan:

On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.

On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.

On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.

In total you spent $11 and covered all the days of your travel.

### Sample2 
>Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]

>Output: 17

Explanation: 

For example, here is one way to buy passes that lets you travel your travel plan:

On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.

On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.

In total you spent $17 and covered all the days of your travel.


## Analysis

一定要找等式关系,既然往外扩展有多种可能,不变的还是天数之间的差值,以此列出状态转移方程

## Code
```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        auto start=days.begin();
        for(int i=0;i<n;++i){
            int b=(int)(upper_bound(start,start+i,days[i]-7)-start);
            int c=(int)(upper_bound(start,start+i,days[i]-30)-start);
            dp[i+1]=min(dp[i]+costs[0],min(dp[b]+costs[1],dp[c]+costs[2]));
        }
        return dp[n];
    }
private:
        int dp[366];
};
```
```cpp
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int end=days[n-1];
        int idx=0;
        int x,y;
        for(int i=days[0];i<=end;++i){
            if(i==days[idx]){
                x=i-7>=0?dp[i-7]:0;
                y=i-30>=0?dp[i-30]:0;
                dp[i]=min(dp[i-1]+costs[0],min(x+costs[1],y+costs[2]));
                idx++;
            }
            else dp[i]=dp[i-1];
        }
        return dp[end];
    }
private:
        int dp[366];
};
```