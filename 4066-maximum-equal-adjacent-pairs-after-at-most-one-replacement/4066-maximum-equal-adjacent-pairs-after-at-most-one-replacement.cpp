class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& arr) {
        map<pair<int,int>,int>mp;
        int n=arr.size();
        int count=0;
        int extra=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                count++;
            }
            else{
                int a=min(arr[i],arr[i+1]);
                int b=max(arr[i],arr[i+1]);
                mp[{a,b}]++;
                extra=max(extra,mp[{a,b}]);
            }
        }
        return count+extra;
    }
};