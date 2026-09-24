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
    unordered_map<int,int>inmap;
    int i=0;
    TreeNode* buildtree(vector<int>&preorder,int low,int high){
        if(low>high){
            return nullptr;
        }
        TreeNode* newnode=new TreeNode(preorder[i]);
        i++;
        int mid=inmap[newnode->val];
        newnode->left=buildtree(preorder,low,mid-1);
        newnode->right=buildtree(preorder,mid+1,high);
        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<preorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return buildtree(preorder,0,inorder.size()-1);
    }
};