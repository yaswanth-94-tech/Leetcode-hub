class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int result=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                result=max(result,((nums[i]-1)*(nums[j]-1)));
            }
        }
        return result;
    }
};