class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int nonzeroes=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]!=0){
                nonzeroes++;
            }
        }
        int result=0;
        for(int i=0;i<nonzeroes;i++){
            if(nums[i]==0){
                result++;
            }
        }
        return result;
    }
};