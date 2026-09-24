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
    void countfunc(TreeNode* root, int& count) {
        if (root == NULL) {
            return;
        }

        countfunc(root->left, count);
        countfunc(root->right, count);
        count++;
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        countfunc(root, count);
        return count;
        
    }
};