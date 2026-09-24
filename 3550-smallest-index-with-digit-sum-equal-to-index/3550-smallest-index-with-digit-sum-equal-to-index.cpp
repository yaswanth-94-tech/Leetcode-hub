class Solution {
public:
    int sod(int &num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum=sum+rem;
            num=num/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int ind=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=sod(nums[i]);
            if(sum==i){
                ind=min(ind,i);
            }
        }
        if(ind==INT_MAX){
            return -1;
        }
        else{
            return ind;
        }
    }
};