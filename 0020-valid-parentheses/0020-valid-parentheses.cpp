class Solution {
public:
    bool isValid(string s) {
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
                if (st.empty() or st.top()!='(') {
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
                if (st.empty() or st.top()!='{') {
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
                if (st.empty() or st.top()!='[') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};