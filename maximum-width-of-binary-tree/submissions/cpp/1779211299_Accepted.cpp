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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            long long minimum=q.front().second;
            long long first=0,last=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long current=q.front().second-minimum;
                q.pop();
                if(i==0){
                    first=current;
                }
                if(i==size-1){
                    last=current;
                }
                if(node->left){
                    q.push({node->left,2*current+1});
                }
                if(node->right){
                    q.push({node->right,2*current+2});
                }
            }
            ans=max(ans,(int)(last-first+1));
        }
        return ans;
    }
};