class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs;
        if(n==1){
            bulbs=brightness;
        }
        else if(n==2){
            bulbs=(brightness+1)/2;
        }
        else{
            bulbs=(brightness+2)/3;
        }
        sort(intervals.begin(),intervals.end());
        long long total=0;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<(int)intervals.size();i++){
            if(intervals[i][0]<=e)
                e=max(e,intervals[i][1]);
            else{
                total=total+e-s+1;
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        total+=e-s+1;
        return (long long)bulbs*total;
    }
};