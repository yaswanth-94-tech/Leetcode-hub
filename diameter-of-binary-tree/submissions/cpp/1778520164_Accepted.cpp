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
    int heightoftree(TreeNode* root,int &diameter){
        if(!root){
            return 0;
        }
        
        int leftheight=heightoftree(root->left,diameter);
        int rightheight=heightoftree(root->right,diameter);
        diameter=max(diameter,leftheight+rightheight);
        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int diameter=0;
        heightoftree(root,diameter);
        return diameter;
    }
};