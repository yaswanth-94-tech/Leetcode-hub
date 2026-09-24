class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        int count=0;
        int i=-1,j=-1;
        int size=s1.size();
        for(int k=0;k<size;k++){
            if(s1[k]!=s2[k]){
                count++;
                if(i==-1){
                    i=k;
                }
                else if(j==-1){
                    j=k;
                }
            }
        }
        
        if(count==2 && s1[i]==s2[j] && s1[j]==s2[i]){
            return true;
        }
        else{
            return false;
        }
    }
};