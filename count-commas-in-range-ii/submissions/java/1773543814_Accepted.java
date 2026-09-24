class Solution {
    public long countCommas(long n) {
        long totalcomma=0;
        long threshold=1000;
        while(threshold<=n){
            totalcomma=totalcomma+n-threshold+1;
            threshold=threshold*1000;
        }
        return totalcomma;
    }
}