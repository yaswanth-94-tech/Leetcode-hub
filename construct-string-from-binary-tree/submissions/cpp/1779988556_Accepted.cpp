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
    void makestring(TreeNode* &root,string &result){
        if(root==NULL){
            return;
        }
        string word=to_string(root->val);
        result=result+word;
        if(root->left){
            result.push_back('(');
            makestring(root->left,result);
            result.push_back(')');
        }
        if(root->right){
            if(!root->left){
                result.push_back('(');
                result.push_back(')');
            }
            result.push_back('(');
            makestring(root->right,result);
            result.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        string result;
        if(!root){
            return "()";
        }
        makestring(root,result);
        return result;
    }
};