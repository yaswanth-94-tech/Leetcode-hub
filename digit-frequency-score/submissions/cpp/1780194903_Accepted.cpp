class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>mp;
        while(n>0){
            int rem=n%10;
            n=n/10;
            mp[rem]++;
        }
        int result=0;
        for(auto it:mp){
            result=result+(it.first*it.second);
        }
        return result;
    }
};