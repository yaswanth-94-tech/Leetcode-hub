/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        while (!q.empty()) {
            int size = q.size();

            vector<int> result2;
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                result2.push_back(node->val);
                for (auto child : node->children) {
                    q.push(child);
                }
            }
            result.push_back(result2);
        }
        return result;
    }
};