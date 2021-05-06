#include<bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        dfs(root,low,high);
        return sum;
    }
private:
    int sum;
    void dfs(TreeNode*root,int low, int high){
        if(root==NULL||root->val<low||root->val>high)return;
        dfs(root->left,low,high);
        sum+=root->val;
        dfs(root->right,low,high);
    }

};
int main(){
	Solution s;
	TreeNode * t=new TreeNode(3);
	s.rangeSumBST(t,7,15);
	return 0;
}
