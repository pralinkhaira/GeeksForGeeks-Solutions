class Solution {
    public:
    int findWays(int n) {
        // If n is odd, we cannot form valid parentheses
        if (n % 2 == 1) {
            return 0;
        }
        
        // n represents the length of the string
        // We need to find the (n/2)-th Catalan number
        int pairs = n / 2;
        
        // dp[i] will store the i-th Catalan number
        vector<long long> dp(pairs + 1, 0);
        dp[0] = 1;
        if (pairs >= 1) dp[1] = 1;
        
        // Calculate Catalan numbers using DP
        // Catalan(n) = sum of Catalan(i) * Catalan(n-1-i) for i from 0 to n-1
        for (int i = 2; i <= pairs; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        
        return dp[pairs];
    }
};