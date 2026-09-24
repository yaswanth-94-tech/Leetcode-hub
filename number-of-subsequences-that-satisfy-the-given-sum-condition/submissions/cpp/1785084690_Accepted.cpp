class Solution {
public:
    int m = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2)%m;
        }
        sort(nums.begin(), nums.end());
        int result = 0;

        int a = 0;
        int b = n - 1;
        while (a <= b) {
            if (nums[a] + nums[b] <= target) {
                result = result%m + power[b - a]%m;
                a++;
            } else {
                b--;
            }
        }
        return result;
    }
};