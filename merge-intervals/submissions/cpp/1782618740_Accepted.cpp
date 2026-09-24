class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        vector<vector<int>>merged;
        sort(intervals.begin(),intervals.end());
        for(auto &it:intervals){
            if(result.empty()){
                result.push_back(it);
            }
            else if(!result.empty() && result.back()[1]>=it[0]){
                result.back()[1]=max(result.back()[1],it[1]);
                continue;
            }
            else if(!result.empty()){
                result.push_back(it);
                continue;
            }
        }
        return result;
    }
};