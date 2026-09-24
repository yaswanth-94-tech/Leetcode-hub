#include <stack>

class Solution {
public:
    int calculate(string s) {
        std::stack<long> st;  // stores previous result and sign
        long result = 0;
        int sign = 1;         // sign can stay int
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                result += sign * num;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                long prevSign = st.top(); st.pop();
                long prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }
        }
        return (int)result;
    }
};