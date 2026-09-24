class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count = 0;
        //{n{freq,vector}}
        int n = nums.size();
        unordered_map<int, int> fq;
        vector<int> arr[101];
        for (int i = 0; i < n; i++) {
            fq[nums[i]]++;
            arr[nums[i]].push_back(i);
        }
        for (auto it : fq) {
            int val = it.first;
            if (fq[val] == 3) {
                if ((arr[val][1] - arr[val][0]) ==
                    (arr[val][2] - arr[val][1])) {
                    count++;
                }
            }
        }
        return count;
    }
};