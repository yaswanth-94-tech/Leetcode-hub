class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        double result = 0;
        int n = prices.size();
        int m = discounts.size();
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int i = 0, j = 0;
        while (i < n && j < m) {

            result += prices[i] * (100.0 - discounts[j]) / 100.0;
            i++;
            j++;
        }
        while (i < n) {
            result += prices[i];
            i++;
        }
        return result;
    }
};