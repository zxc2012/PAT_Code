#include<bits/stdc++.h>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        //copy
        printf("yes");
        RandomListNode* cp=NULL;
        for(RandomListNode* p=pHead;p;p=cp->next){
            cp=new RandomListNode(p->label);
            printf("%d",cp->label);
            cp->next=p->next;
            p->next=cp;
        }
        //random
        for(RandomListNode* p=pHead;p;p=cp->next){
            cp=p->next;
            cp->random=p->random->next;
        }
        //discrete
        RandomListNode* back=pHead;
        RandomListNode* front=back->next;
        RandomListNode* answer=front;
        while(front){
            back->next=front->next;
            front->next=front->next->next;
            back=back->next;
            front=front->next;
        }
        return answer;
    }
};
int main(){
    Solution s;
    int x;
    vector<RandomListNode*> v;
    for(int i=0;i<5;++i){
        scanf("%d",&x);
        RandomListNode* p=new RandomListNode(x);
        v.push_back(p);
    }
    for(int i=0;i<5;++i){
        v[i]->next=i+1<5?v[i+1]:NULL;
        scanf("%d",&x);
        if(x)v[i]->random=v[x];
    }
    RandomListNode *answer = s.Clone(v[0]);
    for(int i=0;i<5;++i){
        printf("%d ",answer->label);
        answer=answer->next;
    }
}