class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int answer=0;
        int size=nums.size();
        int zeros=count(nums.begin(),nums.end(),0);
        for(int i=0;i<size-zeros;i++){
            if(nums[i]==0){
                answer++;
            }
        }
        return answer;
    }
};