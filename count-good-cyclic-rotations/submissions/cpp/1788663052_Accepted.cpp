class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        int h=n/2;
        int count=0;
       
            long long firstsum=0;
            long long hsum=0;
            for(int j=0;j<h;j++){
                firstsum=firstsum+nums[j];
            }
            for(int j=h;j<n;j++){
                hsum=hsum+nums[j];
            }
            for(int i=0;i<n;i++){
                if(firstsum>hsum) count++;

                int leaving=nums[i];
                int mid=nums[(i+h)%n];
                firstsum=firstsum-leaving+mid;
                hsum=hsum-mid+leaving;
            }
        return count;
    }
};