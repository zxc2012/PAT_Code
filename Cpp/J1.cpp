#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL)return 0;
        bool s=pRoot1->val==pRoot2->val;
        printf("%d %d %d\n",pRoot1->val,pRoot2->val,s);
        if(pRoot1->left!=NULL){
            if(s==1)s&=HasSubtree(pRoot1->left,pRoot2->left);
            else return HasSubtree(pRoot1->left,pRoot2);
        }
        if(pRoot1->right!=NULL){
            if(s==1)s&=HasSubtree(pRoot1->right,pRoot2->right);
            else return HasSubtree(pRoot1->right,pRoot2);
        }
        return s;
    }
};
int main(){
    Solution s;
    TreeNode *a=new TreeNode(1);  
    TreeNode *b=new TreeNode(2);
    TreeNode *c=new TreeNode(3);
    TreeNode *d=new TreeNode(4);
    a->left=b,a->right=c,b->left=d;
	printf("%d\n",s.HasSubtree(a,b));
    return 0;
}
