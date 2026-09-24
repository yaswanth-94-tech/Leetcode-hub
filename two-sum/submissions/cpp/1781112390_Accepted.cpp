class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>arr;
        vector<int>result;
        
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        int left=0;
        int right=nums.size()-1;
        
        while(left<right){
            int sum=0;
            sum=arr[left].first+arr[right].first;
            if(sum==target){
                result.push_back(arr[left].second);
                result.push_back(arr[right].second);
                break;
            }
            if(sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return result;
    }
};