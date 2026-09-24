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
    int findmaxpath(TreeNode* root,int &maxpath){
        if(!root){
            return 0;
        }
        int leftside=max(0,findmaxpath(root->left,maxpath));
        int rightside=max(0,findmaxpath(root->right,maxpath));
        maxpath=max(maxpath,leftside+rightside+root->val);
        return (root->val)+max(leftside,rightside);
    }
    int maxPathSum(TreeNode* root) {
        int maxpath=INT_MIN;
        findmaxpath(root,maxpath);
        return maxpath;
    }
};