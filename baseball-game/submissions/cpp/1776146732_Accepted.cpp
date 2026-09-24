#include <bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] != "C" && operations[i] != "D" &&
                operations[i] != "+") {
                st.push(stoi(operations[i]));
            } else if (operations[i] == "C") {

                st.pop();
            } else if (operations[i] == "D") {
                int push = 2 * st.top();
                st.push(push);
            } else if (operations[i] == "+") {
                int sum = st.top();

                st.pop();
                int firstpush = st.top();

                st.push(sum);
                st.push(sum + firstpush);
            }
        }
        int finalsum = 0;
        while (!st.empty()) {

            finalsum += st.top();
            st.pop();
        }
        return finalsum;
    }
};