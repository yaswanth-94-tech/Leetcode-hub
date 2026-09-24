class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result=0;
        sort(cost.begin(),cost.end());
        int size=cost.size();
        for(int i=size-1;i>=0;i=i-3){
            result=result+cost[i];
            if(i-1>=0){
                result=result+cost[i-1];
            }
        }
        return result;
    }
};