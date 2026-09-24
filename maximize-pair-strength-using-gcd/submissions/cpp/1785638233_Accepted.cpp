#include<bits/stdc++.h>
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long result = LLONG_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long gcdVal = gcd(nums[i], nums[j]);
                long long strength = ((long long)nums[i] * nums[j]) / (gcdVal * gcdVal);
                result = max(result, strength);
            }
        }
        
        return result;
    }
};