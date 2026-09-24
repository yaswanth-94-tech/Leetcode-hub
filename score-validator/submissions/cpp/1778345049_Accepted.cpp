#include<bits/stdc++.h>
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        vector<int> result;
        int score=0;
        int counter=0;
        for(auto t:events){
            if(counter>=10){
                break;
            }
            bool isnumber=true;
            for(auto c:t){
                if(!isdigit(c)){
                    isnumber=false;
                    break;
                }
            }
            if(isnumber){
                score+=stoi(t);
            }
            else if(t=="W"){
                counter++;
            }
            else if(t=="WD"){
                score++;
            }
            else if(t=="NB"){
                score++;
            }
        }
        result.insert(result.end(),{score,counter});
        return result;
    }
};