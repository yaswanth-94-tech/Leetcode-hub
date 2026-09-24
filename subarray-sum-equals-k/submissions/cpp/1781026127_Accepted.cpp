class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int lenght=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            
            lenght=lenght+mp[sum-k];
            mp[sum]++;
        }
        return lenght;
    }
};