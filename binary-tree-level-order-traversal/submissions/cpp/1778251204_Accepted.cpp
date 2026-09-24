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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> result;
            int size=q.size();
            for(int i=0;i<size;i++){
                
                TreeNode* newnode=q.front();
                result.push_back(newnode->val);
                q.pop();
                if(newnode->left){
                    q.push(newnode->left);
                }
                if(newnode->right){
                    q.push(newnode->right);
                }
                
            }
            ans.push_back(result);
        }
        return ans;
    }
};