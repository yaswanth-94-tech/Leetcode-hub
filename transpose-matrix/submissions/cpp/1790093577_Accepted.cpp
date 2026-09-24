class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>result(m,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int temp=matrix[i][j];
                if(i==j){
                    result[i][j]=matrix[i][j];
                }
                else{
                    result[j][i]=temp;
                }
            }
        }
        return result;
    }
};