class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto st:operations){
            if(st=="--X"){
                x--;
            }
            else if(st=="X--"){
                x--;

            }
            else if(st=="++X"){
                x++;
            }
            else if(st=="X++"){
                x++;
            }
        }
        return x;

    }
};