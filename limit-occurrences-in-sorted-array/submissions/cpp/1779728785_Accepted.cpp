class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>result;
        int size=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<size;i++){
            
            if(mp[nums[i]]>=k){
                continue;
            }
            else{
                mp[nums[i]]++;
                result.push_back(nums[i]);
            }
            
        }
        return result;
    }
};