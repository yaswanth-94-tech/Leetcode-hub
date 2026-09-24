class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int finalsum=nums[0];
        int size=nums.size();
        for(int i=0;i<size;i++){
            sum=sum+nums[i];
            finalsum=max(sum,finalsum);
            if(sum<0){
                sum=0;
            }
        }
        return finalsum;
    }
};