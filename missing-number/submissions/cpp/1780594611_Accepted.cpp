class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        int expsum=(size*(size+1))/2;
        return expsum-sum;
    }
};