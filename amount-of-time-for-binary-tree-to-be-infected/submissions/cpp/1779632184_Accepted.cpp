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
    void findparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                parent[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                parent[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    TreeNode* findnode(TreeNode* root, int start) {
        if (root == NULL) {
            return nullptr;
        }
        if (root->val == start) {
            return root;
        }
        TreeNode* left = findnode(root->left, start);
        TreeNode* right = findnode(root->right, start);
        if (left) {
            return left;
        } else if (right) {
            return right;
        }
        else{
            return nullptr;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* Node = findnode(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        findparent(root, parent);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(Node);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                visited[temp] = true;
                if (temp->left && !visited[temp->left]) {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if (temp->right && !visited[temp->right]) {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }
                if (parent[temp] && !visited[parent[temp]]) {
                    q.push(parent[temp]);
                    visited[parent[temp]]=true;
                }
            }
            level++;
        }
        return level-1;
    }
};