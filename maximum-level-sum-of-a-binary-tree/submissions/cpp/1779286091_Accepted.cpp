
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
    int maxLevelSum(TreeNode* root) {
        int ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        int maxsum = INT_MIN;
        int level = 1;
        while (!q.empty()) {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {

                TreeNode* tempnode = q.front();

                q.pop();
                sum = sum + tempnode->val;
                if (tempnode->left) {
                    q.push(tempnode->left);
                }
                if (tempnode->right) {
                    q.push(tempnode->right);
                }
            }
            if (sum > maxsum) {
                maxsum = sum;
                ans = level;
                
            }
            level++;
        }

        return ans;
    }
};