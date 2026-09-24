class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a[2]={{nums[0]},{nums[1]}};
        const int n=nums.size();
        for(int i=2;i<n;i++){
            a[a[0].back()<=a[1].back()].push_back(nums[i]);
        }
        a[0].insert(a[0].end(),a[1].begin(),a[1].end());
        return a[0];
    }
};