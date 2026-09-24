class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int count = 0;
        for (int i = 0; i < size-1; i++) {
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        if(nums[size-1]>nums[0]){
            count++;
        }
        return count<=1;
    }
};