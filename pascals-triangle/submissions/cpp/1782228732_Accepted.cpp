class Solution {
public:
    vector<int>formpascal(int n){
        vector<int>result;
        int value=1;
        result.push_back(value);
        for(int i=1;i<n;i++){
            value=value*(n-i)/i;
            result.push_back(value);
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        for(int i=1;i<=numRows;i++){
            result.push_back(formpascal(i));
        }
        return result;
    }
};