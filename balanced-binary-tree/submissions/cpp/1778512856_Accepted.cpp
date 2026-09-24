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
    int heightoftree(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftpart=heightoftree(root->left);
        if(leftpart==-1) return -1;
        int rightpart=heightoftree(root->right);
        if(rightpart==-1) return -1;
        if(abs(leftpart-rightpart)>1) return -1;
        return 1+max(leftpart,rightpart);
    }
    bool isBalanced(TreeNode* root) {
        if(heightoftree(root)!=-1){
            return true;
        }
        else{
            return false;
        }
        
    }
};