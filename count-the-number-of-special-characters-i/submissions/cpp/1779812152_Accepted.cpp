class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>s(word.begin(),word.end());
        int result=0;
        for(char i='a';i<='z';i++){
            if(s.count(i) && s.count(i-'a'+'A')){
                result++;
            }
        }
        return result;
    }
};