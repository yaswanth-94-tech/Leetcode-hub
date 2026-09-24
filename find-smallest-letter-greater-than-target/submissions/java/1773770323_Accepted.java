class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        boolean flag=false;
        char res=letters[0];
        
        for(char ch:letters){
            if(!flag){
            if(ch>target){
                res=ch;
                flag=true;
            }
            else{
                if(ch>target && ch<res){
                    res=ch;
                }
            }
        }
        }
        return res;
    }
}