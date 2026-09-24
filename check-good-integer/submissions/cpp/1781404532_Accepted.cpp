class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum=0;
        int sqaresum=0;
        while(n>0){
            int temp=n%10;
            digitsum=digitsum+temp;
            sqaresum=sqaresum+(temp*temp);
            n=n/10;
        }
        if(sqaresum-digitsum>=50){
            return true;
        }
        else{
            return false;
        }
    }
};