class Solution {
public:
    bool isPalindromic(string s) {
        string b;
        for(char ch:s){
            for(int i=7;i>=0;i--){
                b+=((ch>>i)&1)?'1':'0';
            }
        }
        int l=0,r=b.size()-1;
        while(l<r){
            if(b[l]!=b[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};