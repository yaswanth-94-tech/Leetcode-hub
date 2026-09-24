class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=-1;
        int right=-1;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                left=i;
            }
            if(nums[n-i-1]==target){
                right=n-i-1;
            }
        }
        ans.push_back(right);
        ans.push_back(left);
        return ans;
    }
};