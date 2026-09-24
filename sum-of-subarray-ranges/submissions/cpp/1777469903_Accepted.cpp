class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return summax(nums) - summin(nums);
    }
    long long summax(vector<int> nums) {
        long long sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int maxnum = nums[i];
            for (int j = i; j < n; j++) {
                maxnum = max(maxnum, nums[j]);
                sum = sum + maxnum;
            }
        }
        return sum;
    }
    long long summin(vector<int> nums){
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int minnum=nums[i];
            for(int j=i;j<n;j++){
                minnum=min(minnum,nums[j]);
                sum=sum+minnum;
            }
        }
        return sum;
    }
};