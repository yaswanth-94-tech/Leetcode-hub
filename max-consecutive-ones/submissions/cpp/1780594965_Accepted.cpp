class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result=INT_MIN;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                temp++;
            }
            result=max(result,temp);
            if(nums[i]==0){
                temp=0;
                continue;
            }
        }
        return result;
    }
};