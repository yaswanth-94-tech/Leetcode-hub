class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int result=0;
        for(int i=1;i<n;i++){
            result=max(result,prices[i]-mini);
            mini=min(mini,prices[i]);
        }
        return result;
    }
};