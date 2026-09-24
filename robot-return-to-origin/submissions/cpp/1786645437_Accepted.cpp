class Solution {
public:
    bool judgeCircle(string word) {
        int r1=0,r2=0;
        for (auto ch : word) {
            if (ch == 'R') {
                r1 = r1 + 1;
            }
            if (ch == 'L') {
                r1 = r1 - 1;
            }
            if (ch == 'U') {
                r2 = r2 + 1;
            }
            if (ch == 'D') {
                r2 = r2 - 1;
            }
        }
        if (r1 == 0 && r2 == 0) {
            return true;
        } else {
            return false;
        }
    }
};