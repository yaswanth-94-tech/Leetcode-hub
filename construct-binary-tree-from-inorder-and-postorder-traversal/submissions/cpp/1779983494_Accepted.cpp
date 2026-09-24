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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) {
            return NULL;
        }
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return buildtree(inorder, 0, inorder.size() - 1, postorder, 0,
                         postorder.size() - 1, inmap);
    }
    TreeNode* buildtree(vector<int>& inorder, int instart, int inend,
                        vector<int>& postorder, int poststart, int postend,
                        unordered_map<int, int>& inmap) {
        if (instart > inend || poststart > postend) {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=inmap[postorder[postend]];
        int leftnums=inroot-instart;
        root->left=buildtree(inorder,instart,inroot-1,postorder,poststart,poststart+leftnums-1,inmap);
        root->right=buildtree(inorder,inroot+1,inend,postorder,poststart+leftnums,postend-1,inmap);
        return root;
    }
};