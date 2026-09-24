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
    int helper(TreeNode* root, int result) {
        if (!root) {
            return 0;
        }
        result = result * 10 + root->val;
        if (!root->left && !root->right) {
            return result;
        }

        int left = helper(root->left, result);

        int right = helper(root->right, result);

        return (left + right);
    }
    int sumNumbers(TreeNode* root) {
        int result =helper(root, 0);
        return result;
    }
};