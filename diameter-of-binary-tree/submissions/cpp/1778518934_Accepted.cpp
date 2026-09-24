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
    int heightoftree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftheight = heightoftree(root->left);
        int rightheight = heightoftree(root->right);
        return 1 + max(leftheight, rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int maxi = INT_MIN;
        int left = heightoftree(root->left);
        int right = heightoftree(root->right);
        maxi = max(maxi, left + right);
        maxi = max(maxi, diameterOfBinaryTree(root->left));
        maxi = max(maxi, diameterOfBinaryTree(root->right));
        return maxi;
    }
};