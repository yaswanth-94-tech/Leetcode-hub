class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int>count(51);
        for(int i=0;i<=nums.size()-k;i++){
            vector<int>seen(51,false);
            for(int j=i;j<i+k;j++){
                seen[nums[j]]=true;
            }
            for(int x=0;x<=50;x++){
                if(seen[x]){
                    count[x]++;
                }
            }
        }
        for(int i=50;i>=0;i--){
            if(count[i]==1) return i;
        }
        return -1;
    }
};