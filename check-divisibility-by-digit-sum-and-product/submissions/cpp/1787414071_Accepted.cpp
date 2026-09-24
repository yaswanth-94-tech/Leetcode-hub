class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int dup1 = n;
        int dup2 = n;
        while(dup1>0){
            int rem=dup1%10;
            sum=sum+rem;
            dup1=dup1/10;
        }
        while(dup2>0){
            int rem=dup2%10;
            prod=prod*rem;
            dup2=dup2/10;
        }
        int result=sum+prod;
        if(n%result==0) return true;
        else return false;
    }
};