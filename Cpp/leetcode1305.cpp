#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v1,v2,v3;
        dfs(root1,v1);dfs(root2,v2);
        int i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            if(v1[i]<v2[j])v3.push_back(v1[i++]);
            else v3.push_back(v2[j++]);
        }
        while(i<v1.size())v3.push_back(v1[i++]);
        while(j<v2.size())v3.push_back(v2[j++]);
        return v3;
    }
private:
    void dfs(TreeNode* root,vector<int>& v){
        if(root==NULL)return;
        dfs(root->left,v);
        v.push_back(root->val);printf("\n%d",root->val);
        dfs(root->right,v);
    }
};
int main(){
    TreeNode* r=new TreeNode(2);
    r->left=new TreeNode(1);r->right=new TreeNode(4);
    TreeNode* s=new TreeNode(1);
    s->left=new TreeNode(0);s->right=new TreeNode(3);
    Solution p;
    vector<int>q=p.getAllElements(r,s);    
    return 0;
}
