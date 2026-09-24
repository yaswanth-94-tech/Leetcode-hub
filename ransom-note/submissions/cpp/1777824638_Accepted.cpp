class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> hashtable;
        for(auto c:magazine){
            hashtable[c]++;
        }
        for(auto c:ransomNote){
            if(hashtable[c]<=0){
                return false;
            }
            hashtable[c]--;
        }
        return true;
    }
};