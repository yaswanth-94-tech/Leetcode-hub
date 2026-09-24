bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    // Numbers ending in 0 (except 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    
    // Reverse half of the number
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    
    // For even length: x == reversed
    // For odd length: x == reversed / 10 (middle digit doesn't matter)
    return x == reversed || x == reversed / 10;
}