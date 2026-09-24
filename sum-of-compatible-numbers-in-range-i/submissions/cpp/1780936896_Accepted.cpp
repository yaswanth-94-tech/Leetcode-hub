class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int result;
        for(int i=n-k;i<=n+k;i++){
            if(i>0){
            if(abs(n-i)<=k && (n&i)==0){
                result+=i;
            }
            }
        }
        return result;
    }
};