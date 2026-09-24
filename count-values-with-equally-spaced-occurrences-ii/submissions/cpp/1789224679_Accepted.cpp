class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        unordered_map<int,vector<int>>arr;

        for(int i=0;i<n;i++){
            arr[nums[i]].push_back(i);
        }

        for(auto &it:arr){
            vector<int>&indis=it.second;
            int size=indis.size();
            if(size>=3){
                int diff=indis[1]-indis[0];
                bool space=true;
                for(int i=2;i<size;i++){
                    if((indis[i]-indis[i-1])!=diff){
                        space=false;
                        break;
                    }
                }
                if(space==true){
                    count++;
                }
            }
        }
        return count;
    }
};