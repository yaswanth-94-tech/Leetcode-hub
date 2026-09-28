class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int res=0;
        for(auto ch:s){
            if(ch=='('){
                curr++;
                res=max(res,curr);
            }
            if(ch==')'){
                curr--;
            }
        }
        return res;
    }
};