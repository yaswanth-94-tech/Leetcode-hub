class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        int sr=source[0];
        int sc=source[1];
        int tc=target[1];
        int tr=target[0];
        if(sc==tc and sr==tr)return 0;
        if(sc==tc)return 1;
        if(tr==sr)return 1;
        if(abs(sc-tc)==abs(tr-sr)) return 1;
        else{
            return 2;
        }
    }
};