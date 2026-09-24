class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>res;
        unordered_set<int>present(nums.begin(),nums.end());
        int i=lower;
        while(i<=upper){
            if(present.count(i)){
                i++;
                continue;
            }
            int start=i;
            while(i<=upper && !present.count(i)){
                i++;
                
            }
            res.push_back({start,i-1});
        }
        return res;
    }
};