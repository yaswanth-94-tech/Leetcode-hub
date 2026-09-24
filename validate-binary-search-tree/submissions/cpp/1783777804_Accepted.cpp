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
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isbst(root,LONG_MIN,LONG_MAX);
    }
    bool isbst(TreeNode* root,long leftbond,long rightbond){
        if(!root){
            return true;
        }
        if(root->val<=leftbond || root->val>=rightbond){
            return false;
        }
        return isbst(root->left,leftbond,root->val) && isbst(root->right,root->val,rightbond);
    }
};