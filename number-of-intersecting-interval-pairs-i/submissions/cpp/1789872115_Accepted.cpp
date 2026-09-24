class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<int>arr1=intervals[i];
                vector<int>arr2=intervals[j];
               if(arr2[0] <= arr1[1] && arr1[0] <= arr2[1]) count++;
                
            }
        }
        return count;
    }
};