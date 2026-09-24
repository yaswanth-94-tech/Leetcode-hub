class Solution {
public:

    int lengthOfLastWord(string s) {
        int count=0;
        auto size=s.size();
        int i=size-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            count++;
            i--;
        }
        return count;
    }
};