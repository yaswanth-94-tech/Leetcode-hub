class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int longest = 1;
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(nums[i]);
        }
        for (auto it : set) {
            int x = it;
            int lenght=0;
            if (set.find(x - 1) == set.end()) {
                lenght = 1;
                while (set.find(x + 1) != set.end()) {
                    lenght++;
                    x = x + 1;
                }
            }
            longest = max(longest, lenght);
        }
        return longest;
    }
};