class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==0 || i==n-1){
                result.push_back(nums[i]);
                continue;
            }
            bool left=true;
            for(int j=0;j<i;j++){
                if(nums[j]>=nums[i]){
                    left=false;    
                    break;
                }
            }
            bool right=true;
            for(int j=i+1;j<n;j++){
                if(nums[i]<=nums[j]){
                    right=false;
                    break;
                }
            }
            if(left || right){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};