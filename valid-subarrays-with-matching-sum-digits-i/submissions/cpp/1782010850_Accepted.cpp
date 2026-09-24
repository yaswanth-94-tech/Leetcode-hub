class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum=sum+nums[j];
                long long temp=sum;
                int last=sum%10;
                while(temp>=10){
                    temp=temp/10;
                }
                int first=temp;
                if(first==x && last==x){
                    count++;
                }
            }
        }
        return count;
    }
};