#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>result;
        int minele=*min_element(nums.begin(),nums.end());
        int maxele=*max_element(nums.begin(),nums.end());
        for(int i=minele;i<=maxele;i++){
            if(find(nums.begin(),nums.end(),i)==nums.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};