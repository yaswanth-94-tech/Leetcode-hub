class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int i=series1.size()-1;
        int j=series2.size()-1;

        long long nextval1=0;
        long long nextval2=0;

        vector<vector<int>>result;
        while(i>=0 or j>=0){
            int t1=(i>=0) ? series1[i][0]:-1;
            int t2=(j>=0) ? series2[j][0]:-1;
            int t=max(t1,t2);

            if(i>=0 and series1[i][0]==t){
                nextval1=series1[i][1];
                i--;
            }
            if(j>=0 and series2[j][0]==t){
                nextval2=series2[j][1];
                j--;
            }
            result.push_back({t,(int)(nextval1+nextval2)});
        }
        reverse(result.begin(),result.end());
        return result;
    }
};