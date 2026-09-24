class Solution {
public:
    bool isnondecreasing(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;
        while (isnondecreasing(nums) == false && nums.size() > 1) {
            int mini=INT_MAX;
            int index=-1;
            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                while(sum<mini){
                    mini=sum;
                    index=i;
                }
            }
            nums[index]=nums[index]+nums[index+1];
            nums.erase(nums.begin()+index+1);
            operations++;
        }
        return operations;
       
    }
};