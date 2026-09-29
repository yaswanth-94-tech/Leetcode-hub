class Solution {
public:
    void f(vector<int>&result,int freq,int val){
        for(int i=0;i<freq;i++){
            result.push_back(val);
        }
    }
    vector<int> decompressRLElist(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n;i=i+2){
            int freq=nums[i];
            int val=nums[i+1];
            f(result,freq,val);
        }
        return result;
    }
};