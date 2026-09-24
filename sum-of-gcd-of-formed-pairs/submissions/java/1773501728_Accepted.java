import java.util.Arrays;

class Solution {
    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public long gcdSum(int[] nums) {
        int n = nums.length;
        int mx[] = new int[n];
        int currentmax = nums[0];
        int prefixgcd[] = new int[n];
        for (int i = 0; i < n; i++) {
            currentmax = Math.max(currentmax, nums[i]);
            prefixgcd[i] = gcd(nums[i], currentmax);
        }

        Arrays.sort(prefixgcd);
        long totalsum=0;
        int left=0;
        int right=n-1;
        while(left<right){
            totalsum+=gcd(prefixgcd[left],prefixgcd[right]);
            left++;
            right--;
        }
        return totalsum;
    }
}