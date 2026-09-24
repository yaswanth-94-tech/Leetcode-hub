class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int best = 0;
        for (int skip = -1; skip < n; skip++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (i != skip)
                    arr.push_back(nums[i]);
            }
            int m = arr.size();
            if (m < 2)
                continue;
            vector<int> prefix(m), suffix(m);
            prefix[0] = arr[0];
            for (int i = 1; i < m; i++)
                prefix[i] = __gcd(prefix[i - 1], arr[i]);

            suffix[m - 1] = arr[m - 1];
            for (int i = m - 2; i >= 0; i--)
                suffix[i] = __gcd(suffix[i + 1], arr[i]);
            int count=0;
            for(int i=0;i<m-1;i++){
                if(prefix[i]==suffix[i+1]) count++;
            }
            best=max(best,count);
        }
        return best;
    }
};