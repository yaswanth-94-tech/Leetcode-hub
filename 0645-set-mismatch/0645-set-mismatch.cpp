class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int dup=0;
        int mis=0;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    cnt++;
                }
            }
            if(cnt==2){
                dup=i;
            }
            else if(cnt==0){
                mis=i;
            }
        }
        return {dup,mis};
    }
};