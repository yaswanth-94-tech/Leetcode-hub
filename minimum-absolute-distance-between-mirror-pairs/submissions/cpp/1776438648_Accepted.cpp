class Solution {
public:
    int reverse(int number){
        int rev=0;
        while(number>0){
            rev=rev*10+number%10;
            number=number/10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int> map;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()){
                ans=min(ans,(i-map[nums[i]]));
            }
            map[reverse(nums[i])]=i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};