class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mp;
        for (auto val : nums) {
            mp[val]++;
        }
        while (!mp.empty()) {
            vector<int> v;
            for (auto it : mp) {
                int val = it.first;
                int freq = it.second;

                ans.push_back(val);
                mp[val]--;

                if (mp[val] == 0) {
                    v.push_back(val);
                }
            }
            for(auto it:v){
                mp.erase(it);
            }
        }
        return ans;
    }
};