class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=nums[0];
        int ans=0;
        for(int i=k;i<n;i++){
            maxi=max(maxi,nums[i-k]);
            ans=max(ans,maxi+nums[i]);
        }
        return ans;
    }
};