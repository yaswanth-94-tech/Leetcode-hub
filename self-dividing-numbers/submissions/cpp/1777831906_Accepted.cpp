class Solution {
public:
    bool check(int n){
        int remainder=0;
        int duplicate=n;
        if(n%10==0){
            return false;
        }
        while(n>0){
            remainder=n%10;
            if(remainder==0){
                return false;
            }
            if(duplicate%remainder!=0){
                return false;
            }
            n=n/10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>result;
        for(int i=left;i<=right;i++){
            if(check(i)){
                result.push_back(i);
            }
        }
        return result;
        
    }
};