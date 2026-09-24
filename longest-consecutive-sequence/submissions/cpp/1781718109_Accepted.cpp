class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int longest=0;
        int lastsmaller=INT_MIN;
        int currlong=0;
        for(int i=0;i<n;i++){
            if(nums[i]==lastsmaller){
                continue;
            }
            if(nums[i]-1==lastsmaller){
                currlong++;
                lastsmaller=nums[i];
            }
            else if(nums[i]-1!=lastsmaller){
                currlong=1;
                lastsmaller=nums[i];
            }
            longest=max(longest,currlong);
        }
        return longest;
    }
};