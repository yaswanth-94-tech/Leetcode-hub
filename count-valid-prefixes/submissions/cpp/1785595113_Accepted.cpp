class Solution {
public:
    int countValidPrefixes(string s) {
        int c1=0,c0=0,result=0;
        for(auto ch:s){
            if(ch=='0'){
                c0++;
            }
            else{
                c1++;
            }
            if(abs(c0-c1)<=1) result++;
        }
        return result;
    }
};