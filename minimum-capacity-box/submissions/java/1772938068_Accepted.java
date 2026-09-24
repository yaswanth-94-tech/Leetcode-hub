class Solution {
    public int minimumIndex(int[] capacity, int itemSize) {
        int indexvalue=-1;
        int mincapfound=Integer.MAX_VALUE;
        for(int i=0;i<capacity.length;i++){
            if(capacity[i]>=itemSize && capacity[i]<mincapfound){
                mincapfound=capacity[i];
                indexvalue=i;
                
            }
        }
        
        return indexvalue;
    }
}