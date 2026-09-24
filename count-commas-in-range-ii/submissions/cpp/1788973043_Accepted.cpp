class Solution {
public:
    long long countCommas(long long n) {
        long long th=1000;
        long long tc=0;
        while(th<=n){
            tc=tc+(n-th+1);
            th=th*1000;
        }
        return tc;
    }
};