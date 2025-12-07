class Solution {
public:
    int distinctSubseq(string &str) {
        const long long mod = 1000000007;
        int n = str.size();
        vector<long long> dp(n + 1);
        vector<int> last(26, -1);
        
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2) % mod;
            int c = str[i - 1] - 'a';
            if (last[c] != -1) dp[i] = (dp[i] - dp[last[c] - 1] + mod) % mod;
            last[c] = i;
        }
        
        return dp[n];
    }
};