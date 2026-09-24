class Solution {
public:
    int minimumPushes(string word) {
        vector<int>charcount(26,0);
        for(auto ch:word){
            charcount[ch-'a']++;
        }
        sort(charcount.begin(),charcount.end(),greater<int>());
        int result=0;
        for(int i=0;i<26;i++){
            result=result+charcount[i]*(i/8+1);
        }
        return result;
    }
};