class Solution {
public:
    long long inv2(long long MOD){
        return (MOD+2-1)/2;
    }
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD=1e9+7;
        long long resources=k;
        long long totalops=0;
        long long cost=0;
        for(int i=0;i<(int)nums.size();i++){
            long long need=nums[i];
            if(resources<need){
                long long deficit=need-resources;
                long long ops=(deficit+k-1)/k;
                long long sumcost=((ops%MOD)*(totalops%MOD)%MOD+(ops%MOD)*((ops+1)%MOD)%MOD*inv2(MOD)%MOD)%MOD;
                cost=(cost+sumcost)%MOD;
                resources+=ops*(long long)k;
                totalops+=ops;
            }
            resources-=need;
        }
        return (int)(cost%MOD);
    }
};