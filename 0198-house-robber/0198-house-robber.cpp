class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prevprev=0;
        int take = 0;
        int nontake = 0;
        for (int i = 1; i < n; i++) {
            if (i >= 2) {
                take = nums[i] + prevprev;
            } else {
                take = nums[i];
            }
            nontake = 0 + prev;
            int curr = max(take, nontake);
            prevprev=prev;
            prev=curr;
        }
        return prev;
    }
};