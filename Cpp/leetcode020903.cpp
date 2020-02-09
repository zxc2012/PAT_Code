#include<bits/stdc++.h>
using namespace std;
class TweetCounts {
public:
    TweetCounts() {
        t.clear();mp.clear();
        t.resize(10);
        r=0;
    } 
    void recordTweet(string tweetName, int time) {
        if(mp[tweetName]==0){
            mp[tweetName]=++r;
        }
        t[mp[tweetName]].push_back(time);
    }  
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int f,i;
        if(freq=="minute")f=60;
        else if(freq=="hour")f=3600;
        else if(freq=="day")f=24*3600;
        vector<int>px((endTime-startTime)/f+1,0);
        int index=mp[tweetName];
        for(auto &u:t[index]){
            if(u>endTime||u<startTime)continue;
            else px[(u-startTime)/f]++;
        }
        return px;
    }
private:
    vector<vector<int>> t;
    unordered_map<string,int>mp;
    int r;
};
int main(){
    TweetCounts* tweetCounts = new TweetCounts();
    tweetCounts->recordTweet("tweet0", 13);
    tweetCounts->recordTweet("tweet1", 16);
    tweetCounts->recordTweet("tweet2", 12);    
	tweetCounts->recordTweet("tweet3", 18);  
	tweetCounts->recordTweet("tweet4", 82);
	tweetCounts->recordTweet("tweet3", 89);                            
    vector<int> v1=tweetCounts->getTweetCountsPerFrequency("day", "tweet0", 89, 9471);
    vector<int> v2=tweetCounts->getTweetCountsPerFrequency("hour", "tweet3", 13, 4024);                      
    return 0;
}
