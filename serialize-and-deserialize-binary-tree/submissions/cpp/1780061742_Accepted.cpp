/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "#,";
        }
        
        string result = to_string(root->val)+",";
        string left = serialize(root->left);
        string right = serialize(root->right);
        result.append(left);
        result.append(right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializehelper(ss);
    }
    TreeNode* deserializehelper(istringstream &ss){
        string token;
        getline(ss,token,',');
        if(token=="#"){
            return nullptr;
        }
        else{
            TreeNode* root=new TreeNode(stoi(token));
            root->left=deserializehelper(ss);
            root->right=deserializehelper(ss);
            return root;
        }
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));