class Solution {
    public int countCommas(int n) {
        int totalcomma=0;
        int threshold=1000;
        while(threshold<=n){
            totalcomma=totalcomma+n-threshold+1;
            threshold=threshold*1000;
        }
        return totalcomma;
    }
}