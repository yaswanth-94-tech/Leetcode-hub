class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char ch=s[i];
            int ir=26-(ch-'a');
            int prod=ir*(i+1);
            sum=sum+prod;
        }
        return sum;
    }
};