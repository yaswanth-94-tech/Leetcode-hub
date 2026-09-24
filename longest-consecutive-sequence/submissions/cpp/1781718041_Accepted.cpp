class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int longest=0;
        int lastelement=INT_MIN;
        int currlong=0;
        for(int i=0;i<n;i++){
            if(nums[i]==lastelement){
                continue;
            }
            if(nums[i]-1==lastelement){
                currlong++;
                lastelement=nums[i];
            }
            else if(nums[i]-1!=lastelement){
                currlong=1;
                lastelement=nums[i];
            }
            longest=max(longest,currlong);
        }
        return longest;
    }
};