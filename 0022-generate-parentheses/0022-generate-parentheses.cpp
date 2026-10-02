class Solution {
public:
    bool isvalid(string s) {
        int n = s.size();
        if (n & 1)
            return false;
        stack<int> st;
        for (auto it : s) {
            if (it == '(') {
                st.push(it);
                continue;
            }
            if (it == ')') {
                if (st.empty() or st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            }
            if (it == '{') {
                st.push(it);
                continue;
            }
            if (it == '}') {
                if (st.empty() or st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
            }
            if (it == '[') {
                st.push(it);
                continue;
            }
            if (it == ']') {
                if (st.empty() or st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    void generate(string res, int& n, vector<string>& ans) {
        if (res.size() == 2 * n) {
            if (isvalid(res) == true) {
                ans.push_back(res);
            }
        } else {
            res.push_back('(');
            generate(res, n, ans);
            res.pop_back();
            res.push_back(')');
            generate(res, n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {""};
        }
        vector<string> ans;
        string res = "";
        generate(res, n, ans);
        return ans;
    }
};