class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        string s = "";
        for (auto c : chunks)
            s += c;

        unordered_map<string, int> freq;
        int n = s.size();
        int i = 0;

        while (i < n) {
            if (!islower(s[i]) && s[i] != '-') {
                i++;
                continue;
            }
            int j = i;
            bool valid = true;
            while (j < n && (islower(s[j]) || s[j] == '-'))
                j++;

            string token = s.substr(i, j - i);

            if (token.front() == '-' || token.back() == '-') {
                valid = false;
            } else {
                for (int k = 0; k < (int)token.size(); k++) {
                    if (token[k] == '-') {
                        if (k == 0 || k == (int)token.size() - 1 ||
                            !islower(token[k - 1]) || !islower(token[k + 1])) {
                            valid = false;
                            break;
                        }
                    }
                }
            }

            if (valid && !token.empty()) {
                freq[token]++;
            } else {
                int k = 0, tlen = token.size();
                while (k < tlen) {
                    if (token[k] == '-') {
                        k++;
                        continue;
                    }
                    int start = k;
                    while (k < tlen) {
                        if (islower(token[k])) {
                            k++;
                        } else if (token[k] == '-' && k + 1 < tlen &&
                                   islower(token[k + 1])) {
                            k++;
                        } else {
                            break;
                        }
                    }
                    string word = token.substr(start, k - start);
                    while (!word.empty() && word.back() == '-')
                        word.pop_back();
                    if (!word.empty())
                        freq[word]++;
                }
            }

            i = j; 
        }

       
        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(freq.count(q) ? freq[q] : 0);
        }
        return ans;
    }
};