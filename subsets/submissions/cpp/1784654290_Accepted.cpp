class Solution {
public:
vector<vector<int>> result;
    void helper(int index,vector<int>&temp,vector<int>& nums,int n){
        if(index==n){
            result.push_back(temp);
            return;
        }
        helper(index+1,temp,nums,n);
        temp.push_back(nums[index]);
        helper(index+1,temp,nums,n);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        helper(0,temp,nums,n);
        return result;
    }
};