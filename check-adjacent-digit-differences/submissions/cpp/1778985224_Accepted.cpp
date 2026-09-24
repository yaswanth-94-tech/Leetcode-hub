class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        bool result=true;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(abs(s[i]-s[i+1])>2){
                result=false;
                break;
            }
        }
        return result;
    }
};