class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        long long middle=(n/2);
        if(mp[nums[middle]]==1){
            return true;
        }
        else{
            return false;
        }
        
    }
};