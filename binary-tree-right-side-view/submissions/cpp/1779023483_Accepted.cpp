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
    void findrightview(TreeNode* root, vector<int>& result, int level) {
        if (!root) {
            return;
        }
        if (level == result.size()) {
            result.push_back(root->val);
        }

        findrightview(root->right, result, level + 1);

        findrightview(root->left, result, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        findrightview(root, result, level);
        return result;
    }
};