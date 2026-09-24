class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        unordered_map<int,vector<int>>mp;
        int range=INT_MIN;
        for(auto it:nums){
            int maxi=INT_MIN;
            int mini=INT_MAX;
            int temp=it;
            while(it!=0){
                int last=it%10;
                maxi=max(maxi,last);
                mini=min(mini,last);
                it=it/10;
            }
            int currange=maxi-mini;
            range=max(range,maxi-mini);
            mp[currange].push_back(temp);
        }
        for(auto it:mp[range]){
            sum=sum+it;
        }
        return sum;
    }
};