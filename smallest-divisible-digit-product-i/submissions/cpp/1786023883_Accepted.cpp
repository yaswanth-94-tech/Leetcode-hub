class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;;i++){
            int num=i;
            int prod=1;
            while(num>0){
                int rem=num%10;
                num=num/10;
                prod=prod*rem;
            }
            if(prod%t==0){
                return i;
            }
            else{
                continue;
            }
        }
    }
};