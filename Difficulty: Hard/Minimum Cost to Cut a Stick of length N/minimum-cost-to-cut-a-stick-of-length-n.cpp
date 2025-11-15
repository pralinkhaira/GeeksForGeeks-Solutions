class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        
        // Add boundaries 0 and n
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        // DP table
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));

        // len = length of interval
        for (int len = 2; len < m + 2; len++) {
            for (int i = 0; i + len < m + 2; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++) {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[0][m + 1];
    }
};

