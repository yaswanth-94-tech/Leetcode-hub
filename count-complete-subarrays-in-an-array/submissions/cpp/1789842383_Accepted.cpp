class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = unordered_set(nums.begin(), nums.end()).size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                if (st.size() == k)
                    res++;
            }
        }
        return res;
    }
};