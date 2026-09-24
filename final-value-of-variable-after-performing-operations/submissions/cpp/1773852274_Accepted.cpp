class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto st : operations) {
            if (st == "--X" || st == "X--") {
                x--;
            } else {
                x++;
            }
        }
        return x;
    }
};