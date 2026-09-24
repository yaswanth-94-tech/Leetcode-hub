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
    int dfs(TreeNode* root,int &maxlength){
        if(!root){
            return 0;
        }
        int leftheight=dfs(root->left,maxlength);
        int rightheight=dfs(root->right,maxlength);
        maxlength=max(maxlength,leftheight+rightheight);
        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxlength=0;
        dfs(root,maxlength);
        return maxlength;
    }
};