class Solution {
public:
    int ladderLength(string beginword, string endword,
                     vector<string>& wordlist) {
        int result = 0;
        queue<pair<string, int>> q;
        q.push({beginword, 1});
        unordered_set<string> set(wordlist.begin(), wordlist.end());

        while (!q.empty()) {
            string word = q.front().first;
            int times = q.front().second;
            q.pop();
            if(word==endword) return times;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (set.find(word) != set.end()) {
                        set.erase(word);
                        q.push({word, times + 1});
                    }
                }
                word[i] = ch;
            }
           
        }
        return 0;
    }
};