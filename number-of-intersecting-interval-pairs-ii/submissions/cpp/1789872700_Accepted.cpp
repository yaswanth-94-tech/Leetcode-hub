class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<int>starts(n);
        for(int i=0;i<n;i++){
            starts[i]=intervals[i][0];
        }
        long long count=0;
        for(int i=0;i<n;i++){
            int idx=upper_bound(starts.begin(),starts.end(),intervals[i][1])-starts.begin();
            count=count+idx-(i+1);
        }
        return count;
    }
};