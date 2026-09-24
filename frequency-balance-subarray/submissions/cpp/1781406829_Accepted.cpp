class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            int maxfreq = 0;
            for (int j = i; j < n; j++) {
                freq[nums[j]]++;

                maxfreq=max(maxfreq,freq[nums[j]]);
                bool valid = true;
                if (freq.size() == 1) {
                    valid = true;
                } else if (maxfreq % 2 != 0) {
                    valid = false;
                } else {
                    int half = maxfreq / 2;
                    int halfcount = 0;
                    for (auto [val, count] : freq) {
                        if (count != maxfreq && count != half) {
                            valid = false;
                            break;
                        }
                        if (count == half) {
                            halfcount++;
                        }
                    }
                    if (valid && halfcount == 0)
                        valid = false;
                }
                if (valid == true) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};