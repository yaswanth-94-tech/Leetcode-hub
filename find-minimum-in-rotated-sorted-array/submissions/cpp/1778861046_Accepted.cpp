#include<bits/stdc++.h>
class Solution {
public:
    int findMin(vector<int>& nums) {
        int result;
        result=*min_element(nums.begin(),nums.end());
        return result;
    }
};