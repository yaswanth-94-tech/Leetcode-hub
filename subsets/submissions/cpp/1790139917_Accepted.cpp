class Solution {
public:
    void subsets(int index, int n, vector<vector<int>>& result,
                 vector<int>& nums, vector<int>& temp) {
        if (index >= n) {
            result.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        subsets(index + 1, n, result, nums,temp);

        temp.pop_back();
        subsets(index + 1, n, result, nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = nums.size();
        subsets(0, n, result, nums, temp);
        return result;
    }
};