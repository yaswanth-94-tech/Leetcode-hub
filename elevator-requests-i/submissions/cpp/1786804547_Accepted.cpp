class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int start=0;
        int time=0;
        for(auto it:requests){
            time+=abs(start-it);
            start=it;
        }
        return time;
    }
};