/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findmaxpath(TreeNode* root,int &result){
        if(!root){
            return 0;
        }
        int leftside=max(0,findmaxpath(root->left,result));
        int rightside=max(0,findmaxpath(root->right,result));
        result=max(result,root->val+leftside+rightside);
        return root->val+max(leftside,rightside);
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        findmaxpath(root, result);
        return result;
    }
};