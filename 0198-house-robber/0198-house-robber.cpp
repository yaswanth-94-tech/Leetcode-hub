class Solution {
public:
    int f(int index, vector<int>& nums, vector<int>& dp) {
        if (index < 0) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }

        if (index == 0) {
            return nums[0];
        }

        long long pick = nums[index] + f(index - 2, nums, dp);
        long long notpick = 0 + f(index - 1, nums, dp);
        long long maxi = notpick;
        if (pick > maxi)
            maxi = pick;
        return dp[index] = maxi;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, nums, dp);
    }
};