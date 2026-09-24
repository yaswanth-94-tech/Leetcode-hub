class Solution {
public:
    int passwordStrength(string password) {
        int result=0;
        unordered_set<char>s;
        for(auto it:password){
            s.insert(it);
        }
        for(auto it:s){
            if(islower(it)){
                result=result+1;
            }
            else if(isupper(it)){
                result=result+2;
            }
            else if(isdigit(it)){
                result=result+3;
            }
            else if(it=='!' || it=='@' || it=='#' || it=='$'){
                result=result+5;
            }
        }
        return result;
    }
};