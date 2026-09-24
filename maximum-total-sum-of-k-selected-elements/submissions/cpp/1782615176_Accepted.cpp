class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        // long long arr[k];
        vector<int>multi(k);
        for(int i=0;i<k;i++){
            multi[i]=mul-i;
        }
        sort(multi.rbegin(),multi.rend());
        long long result=0;
        for(int i=0;i<k;i++){
            if(multi[i]>1){
                result+=(long long)multi[i]*nums[i];
            }
            else{
                result+=nums[i];
            }
        }
        return result;
    }
};