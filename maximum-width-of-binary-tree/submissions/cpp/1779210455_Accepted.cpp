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
#include <bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = INT_MIN;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            auto data = q.front();

            long long min = data.second;
            long long first=0, last=0;
            for (int i = 0; i < size; i++) {
                long long current = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0)
                    first = current;
                if (i == size - 1)
                    last = current;
                if (node->left) {
                    q.push({node->left, 2 * current + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * current + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1));
        }
        return ans;
    }
};