#include<bits/stdc++.h>
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        string s;
        for(auto it:nums){
            s=s+to_string(it);
        }
        vector<int>result;
        for(auto it:s){
            int value=stoi(string(1,it));
            result.push_back(value);
        }
        return result;
    }
};