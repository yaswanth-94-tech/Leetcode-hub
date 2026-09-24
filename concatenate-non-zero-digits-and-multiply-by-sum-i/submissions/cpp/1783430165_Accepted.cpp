class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        string result;
        long long sum=0;
        while(n!=0){
            long long rem=n%10;
            if(rem>0){
                sum=sum+rem;
                result+=to_string(rem);
            }
            n=n/10;
        }
        reverse(result.begin(),result.end());
        long long temp=stoll(result);
        temp=temp*sum;
        return temp;
    }
};