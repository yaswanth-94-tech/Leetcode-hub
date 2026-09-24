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
    int i=0;
    TreeNode* buildtree(vector<int>preorder,int bound){
        if(i==preorder.size() || preorder[i]>bound){
            return nullptr;
        }
        TreeNode* newnode=new TreeNode(preorder[i]);
        i++;
        newnode->left=buildtree(preorder,newnode->val);
        newnode->right=buildtree(preorder,bound);
        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return buildtree(preorder,INT_MAX);
    }
};