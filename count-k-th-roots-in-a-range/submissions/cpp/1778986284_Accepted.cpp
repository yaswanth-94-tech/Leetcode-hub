class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        int count=0;
        if(l==0){
            count++;
        }
        long long x=1;
        
        while(true){
            long long power=1;
            bool overflow=false;
            for(int i=0;i<k;i++){
                power=power*x;
                if(power>r){
                    overflow=true;
                    break;
                }
                
            }
            if(overflow){
                break;
            }
            if(power>=l && power<=r){
               
                count++;
            }
            x++;
        }
        return count;
    }
};