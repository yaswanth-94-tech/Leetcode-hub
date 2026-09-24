#include<bits/stdc++.h>
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size();
        int size2=nums2.size();
        unordered_set<int>set1;
        unordered_set<int>set2;

        
        for(int i=0;i<size2;i++){
            set2.insert(nums2[i]);
        }
        for(int i=0;i<size1;i++){
            if(set2.find(nums1[i])!=set2.end()){
                return nums1[i];
            }
        }
        return -1;
    }
};