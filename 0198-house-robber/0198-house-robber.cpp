class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        int take=0;
        int nontake=0;
        for(int i=1;i<n;i++){
            if(i>=2){
                 take=nums[i]+dp[i-2];
            }
            else{
                take=nums[i];
            }
             nontake=0+dp[i-1];
            dp[i]=max(take,nontake);
        }
        return dp[n-1];
    }
};