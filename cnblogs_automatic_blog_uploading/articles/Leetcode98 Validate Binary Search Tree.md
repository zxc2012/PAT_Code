Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.
```cpp
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
 ```
 time O(n) space O(1)
 ```cpp
 class Solution {
public:
    int* last = NULL;
    bool isValidBST(TreeNode* root) {
        if (root){
            if(!isValidBST(root->left)) return false;
            if (last && *last>=root->val) return false;
            last = &root->val;
            if(!isValidBST(root->right)) return false;
            return true;
        }else return true;
    };
};
 ```