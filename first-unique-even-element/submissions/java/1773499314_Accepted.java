class Solution {
    public int firstUniqueEven(int[] nums) {
        HashMap<Integer,Integer> count=new HashMap<>();
        for(int n:nums){
            if(n%2==0){
                count.put(n,count.getOrDefault(n,0)+1);
                
            }
        }
        for(int n:nums){
            if(n%2==0 && count.get(n)==1){
                return n;
            }
        }
        return -1;
    }
}