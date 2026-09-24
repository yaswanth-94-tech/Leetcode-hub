class Solution {
public:
    int myAtoi(string s) {
        long result=0;
        int sign=1;
        int i=0;
        int n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n){
            return 0;
        }
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<n && isdigit(s[i])){
            result=result*10+(s[i]-'0');
            if(sign*result > INT_MAX) return INT_MAX;
            if(sign*result < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(result*sign);
    }
};