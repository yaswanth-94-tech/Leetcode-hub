class Solution {
public:
    int minDays(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        vector<int>tri;
        for(int i=1;i*(i+1)/2<=n;i++) tri.push_back(i*(i+1)/2);

        for(int s=0;s<=n;s++){
            if(dp[s]==INT_MAX) continue;
            for(int idx=0;idx<tri.size();idx++){
                int k=idx+1;
                int t=tri[idx];
                if(s+t>n) break;
                int cost=k+(s==0 ? 0:1);
                if(dp[s]+cost<dp[s+t]){
                    dp[s+t]=dp[s]+cost;
                }
            }
        }
        return dp[n];
    }
};