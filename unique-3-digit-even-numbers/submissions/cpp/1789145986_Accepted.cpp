class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        unordered_map<int, int> mp;
        for (auto it : digits) {
            mp[it]++;
        }
        for (int i = 100; i <= 999; i++) {
            if ((i % 2) != 0)
                continue;
            else {
                int num=i;
                int n = num % 10;
                num = num / 10;
                int m = num % 10;
                num = num / 10;
                int o = num % 10;
                num = num / 10;
                unordered_map<int, int> freq;
                freq[n]++;
                freq[m]++;
                freq[o]++;
                bool st = true;
                for (int d = 0; d <= 9; d++) {
                    if (mp[d] < freq[d]) {
                        st = false;
                        break;
                    }
                }
                if (st == true)
                    count++;
            }
        }
        return count;
    }
};