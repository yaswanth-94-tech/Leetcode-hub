class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        long long q = 0, minSum = 0;
        long long super[2] = {0, LLONG_MIN};

        for (int j = 1; j <= n; j++) {
            long long val = nums[j - 1];
            q += (j % 2 == 1) ? val : -val;
            int p = j % 2;
            if (super[p] != LLONG_MIN)
                minSum = min(minSum, q - super[p]);
            super[p] = max(super[p], q);
        }
        return q + max(0LL, -2 * minSum);
    }
};