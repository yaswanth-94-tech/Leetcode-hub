class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<size;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            if(it.second==1){
                return it.first;
            }
            else{
                continue;
            }
        }
        return 1;
    }
};