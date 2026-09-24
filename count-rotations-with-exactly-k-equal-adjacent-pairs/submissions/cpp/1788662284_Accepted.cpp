class Solution {
public:
    int countRotations(string s, int k) {
        int count=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            int score=0;
            for(int j=0;j<n-1;j++){
                if(s[j]==s[j+1]) score++;
            }
            if(score==k) count++;
            char first=s[0];
            s=s.substr(1)+first;
        }
        return count;
    }
};