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
    void findrightview(TreeNode* root,int level,vector<int>&result){
        if(!root){
            return;
        }
        if(result.size()==level){
            result.push_back(root->val);
        }
        if(root->right){
            findrightview(root->right,level+1,result);
            
        }
        if(root->left){
            findrightview(root->left,level+1,result);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level=0;
        findrightview(root,level,result);
        return result;
    }
};