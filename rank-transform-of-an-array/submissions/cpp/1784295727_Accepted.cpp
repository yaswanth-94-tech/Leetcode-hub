class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> dummy = arr;
        vector<int> result;
        sort(dummy.begin(), dummy.end());
        unordered_map<int, int> mp;
        for (int x : dummy) {
            if (mp.find(x) == mp.end()) {
                mp[x] = mp.size() + 1;
            }
        }
        for (int x : arr) {
            result.push_back(mp[x]);
        }
        return result;
    }
};