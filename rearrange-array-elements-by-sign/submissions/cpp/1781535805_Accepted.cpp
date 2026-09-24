class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        int neg=1;
        vector<int> result(n);
        for(auto it:nums){
            if(it>0){
                result[pos]=it;
                pos=pos+2;
            }
            else{
                result[neg]=it;
                neg=neg+2;
            }
        }
        return result;
    }
};