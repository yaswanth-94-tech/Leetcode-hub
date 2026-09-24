class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int oddcount=0;
        int evencount=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]%2==0){
                evencount++;
                result[i]=oddcount;
            }
            else if(nums[i]%2!=0){
                oddcount++;
                result[i]=evencount;
            }
        }
        return result;

    }
};