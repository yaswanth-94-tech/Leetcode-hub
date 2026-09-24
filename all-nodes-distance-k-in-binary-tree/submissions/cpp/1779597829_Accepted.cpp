/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parentnodes) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                parentnodes[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                parentnodes[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> parentnodes;
        findparent(root, parentnodes);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int currentlevel=0;
        while(!q.empty()){
            int size=q.size();
            if((currentlevel++)==k) break;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();

                if(temp->left && !visited[temp->left]){
                    q.push(temp->left);
                    visited[temp->left]=true;
                }
                if(temp->right && !visited[temp->right]){
                    q.push(temp->right);
                    visited[temp->right]=true;
                }
                if(parentnodes[temp] && !visited[parentnodes[temp]]){
                    q.push(parentnodes[temp]);
                    visited[parentnodes[temp]]=true;
                }
            }
        }
        while(!q.empty()){
            TreeNode* node=q.front();

            result.push_back(node->val);
            q.pop();
        }
        return result;
    }
};