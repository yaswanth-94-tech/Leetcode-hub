class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                ans.push_back(i%2);

            }
            else{
                ans.push_back(1-i%2);
            }
        }
        return ans;
    }
};