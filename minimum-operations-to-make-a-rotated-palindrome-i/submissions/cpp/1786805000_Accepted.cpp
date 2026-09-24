class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        int result=INT_MAX;
        for(int r=0;r<n;r++){
            int cost=0;
            for(int i=0,j=n-1;i<j;i++,j--){
                int a=s[(r+i)%n]-'a';
                int b=s[(r+j)%n]-'a';
                int diff=abs(a-b);
                cost+=min(diff,26-diff);
            }
            cost+=r;
            result=min(result,cost);
        }
        return result;
    }
};