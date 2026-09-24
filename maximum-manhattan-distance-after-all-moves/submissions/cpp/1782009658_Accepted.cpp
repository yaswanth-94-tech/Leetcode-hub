class Solution {
public:
    int maxDistance(string moves) {
        int result=0;
        string dirs="UDLR";
        for(char ch:dirs){
            int x=0,y=0;
            for(char c:moves){
                char actual=(c=='_')?ch:c;
                if(actual=='U')y++;
                else if(actual=='D')y--;
                else if(actual=='L')x--;
                else if(actual=='R')x++;
            }
             result=max(result,abs(x)+abs(y));
        }
       return result;
    }
};