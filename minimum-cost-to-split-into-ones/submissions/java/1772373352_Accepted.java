class Solution {
    public int minCost(int n) {
        int val = (int) n;
        return (val * (val - 1)) / 2;
    }
}