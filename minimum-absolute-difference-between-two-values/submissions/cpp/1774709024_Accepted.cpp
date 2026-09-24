class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int firstone=-1;
        int firstsecond=-1;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                firstone=i;
                if(firstsecond!=-1){
                    ans=min(ans,abs(firstone-firstsecond));
                }
            }
            if(nums[i]==2){
                firstsecond=i;
                if(firstone!=-1){
                    ans=min(ans,abs(firstone-firstsecond));
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
        
    }
};