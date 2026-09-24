class Solution {
public:
    bool isprime(int n) {
        if (n < 2) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        for (int i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int reverse = 0;
        int temp = n;
        while (temp) {
            reverse = reverse * 10 + temp % 10;
            temp = temp / 10;
        }

        int smalln = min(reverse, n);
        int largen = max(reverse, n);
        int sum = 0;
        for (int i = smalln; i <= largen; i++) {
            if (isprime(i)) {
                sum += i;
            }
        }
        return sum;
    }
};