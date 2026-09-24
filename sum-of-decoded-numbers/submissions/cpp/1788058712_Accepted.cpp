class Solution {
public:
    const long long mod = 1e9 + 7;
    long long fastpow(long long x, long long y) {
        x %= mod;
        long long result = 1;
        while (y > 0) {
            if (y & 1)
                result = (result * x) % mod;
            x = (x * x) % mod;
            y >>= 1;
        }
        return result;
    }
    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for (long long num : nums) {
            long long width = num % 10;
            long long d = num / 10;

            string s = to_string(d);
            long long x = stoll(s.substr(0, width));
            long long y =stoll( s.substr(width));

           
            
            ans = (ans + fastpow(x,y)) % mod;
        }
        return (int)ans;
    }
};