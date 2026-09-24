#include<bits/stdc++.h>
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lcount=0,rcount=0,dashcount=0;

        for(auto st:moves){
            if(st=='L'){
                lcount++;
            }
            else if(st=='R'){
                 rcount++;
            }
            else{
                 dashcount++;
            }
        }
        int answer=abs(lcount-rcount)+dashcount;
        return answer;
    }
};