#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, index}
    int ind;

    StockSpanner() {
        ind = -1;
    }
    
    int next(int price) {
        ind++;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);

        st.push({price, ind});

        return ans;
    }
};