class Solution {
public:
    struct greater{
        bool operator()(const int &a,const int &b) const{
            return a>b;
        }
    };
    int findLucky(vector<int>& arr) {
        map<int,int,greater>mp;
        int size=arr.size();
        for(int i=0;i<size;i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.second==it.first){
                return it.first;
            }
        }
        return -1;
    }
};