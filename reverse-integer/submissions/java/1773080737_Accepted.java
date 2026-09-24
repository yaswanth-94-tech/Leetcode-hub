class Solution {
    public int reverse(int x) {
        long res = 0; 
        while (x != 0) {
            int rem = x % 10;
            res = res * 10 + rem;
            x = x / 10;
        }
        
        // Check if res is within the valid int range
        if (res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) {
            return 0;
        }
        
        return (int) res;
    }
}