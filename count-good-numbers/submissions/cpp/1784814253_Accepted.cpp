class Solution {
public:
    int mod = 1e9 + 7;
    int findpower(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = ans * a;
                ans = ans % mod;
                b--;
            } else {
                a = a * a;
                a = a % mod;
                b = b / 2;
            }
        }
        return ans % mod;
    }
    int countGoodNumbers(long long n) {
        long long a = findpower(5, (n + 1) / 2);
        long long b = findpower(4, n / 2);
        return (int)((a * b) % mod);
    }
};