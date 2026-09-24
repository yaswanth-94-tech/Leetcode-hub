class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(),occupiedIntervals.end());
        vector<vector<int>>merged;
        for(auto &it:occupiedIntervals){
            if(!merged.empty() && it[0]<=merged.back()[1]+1){
                merged.back()[1]=max(merged.back()[1],it[1]);
            }
            else{
                merged.push_back(it);
            }
        }
        vector<vector<int>>result;
        for(auto &iv:merged){
            int s=iv[0],e=iv[1];
            if(e<freeStart|| s>freeEnd){
                result.push_back({s,e});
                continue;
            }
            if(s<freeStart){
                result.push_back({s,freeStart-1});
            }
            if(e>freeEnd){
                result.push_back({freeEnd+1,e});
            }
        }
        return result;
    }
};