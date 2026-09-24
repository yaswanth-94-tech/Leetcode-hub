class Solution {
public:
    double myPow(double x, int n) {
        double result=1;
        long pw=n;
        if(pw<0){
            pw=pw*-1;
        }
        while(pw){
            if(pw%2==1){
                result=result*x;
                pw=pw-1;
            }
            else{
                x=x*x;
                pw=pw/2;
            }
        }
        if(n<0){
            result=1/result;
        }
        return result;
    }
};