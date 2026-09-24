class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> freq;
        unordered_map<char, int> firstpos;
        vector<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (vowels.count(s[i])) {
                v.push_back(s[i]);
                freq[s[i]]++;
                if (!firstpos.count(s[i])) {
                    firstpos[s[i]] = i;
                }
            }
        }
        sort(v.begin(), v.end(), [&](char a, char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            }
            return firstpos[a] < firstpos[b];
        });
        int j = 0;
        for(int i=0;i<s.size();i++){
            if(vowels.count(s[i])){
                s[i]=v[j];
                j++;
            }
        }
        return s;
    }
};