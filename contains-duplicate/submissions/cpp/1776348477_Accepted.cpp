class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int n:nums){
            if(set.find(n)!=set.end()){
                return true;
            }
            else{
                set.insert(n);
            }
        }
        return false;
    }
};