class Solution {
public:
    int largestInteger(int n, int s) {
        if(s>9*n){
            return -1;
        }
        string res(n,'0');
        int remaining=s;
        for(int i=0;i<n && remaining >0;i++){
            int digit =min(9,remaining);
            res[i]=char('0'+digit);
            remaining=remaining - digit;
        }
        return stoll(res);
    }
};