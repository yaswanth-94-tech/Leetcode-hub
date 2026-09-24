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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newnode=new TreeNode;
            newnode->val=val;
            return newnode;
        }
        TreeNode* head=root;
        while(root){
            if(val>root->val){
                TreeNode* temp=root;
                root=root->right;
                if(!root){
                    TreeNode* newnode=new TreeNode;
                    newnode->val=val;
                    temp->right=newnode;
                    return head;
                }
            }
            else{
                TreeNode* temp=root;
                root=root->left;
                if(!root){
                    TreeNode* newnode=new TreeNode;
                    newnode->val=val;
                    temp->left=newnode;
                    return head;
                }
            }
        }
        return head;
    }
};