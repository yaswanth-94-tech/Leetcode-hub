class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                sum=sum+nums[i];
            }
            else{
                sum=sum+nums[i];
            }
            ans=max(ans,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};