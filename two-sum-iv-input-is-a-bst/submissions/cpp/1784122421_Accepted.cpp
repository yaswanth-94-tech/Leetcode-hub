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
    vector<int> inorder;
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        findTarget(root->left, k);
        inorder.push_back(root->val);
        findTarget(root->right, k);
        int n=inorder.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int sum=inorder[low]+inorder[high];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                low++;
            }
            else{
                high--;
            }
        }
        return false;
    }
};