class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);
        for (auto c : s) {
            freq[c]++;
        }
        int result = 0;
        unordered_set<char> visited;
        for (auto c : s) {
            if (visited.count(c))
                continue;
            char m;
            if (isdigit(c)) {
                m = '9' - (c - '0');

            } else {
                m = 'z' - (c - 'a');
            }
            result = result + abs(freq[c] - freq[m]);
            visited.insert(c);
            visited.insert(m);
        }
        return result;
    }
};