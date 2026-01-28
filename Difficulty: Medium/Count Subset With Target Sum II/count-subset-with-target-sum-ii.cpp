class Solution {
  public:
    int countSubset(vector<int> &arr, int k) {
        int n = arr.size();

        bool allNegative = true;
        for (int x : arr) {
            if (x >= 0) {
                allNegative = false;
                break;
            }
        }

        if (allNegative) {
            return 0;
        }

        vector<int> dp(k + 1, 0);
        dp[0] = 1;

        for (int x : arr) {
            if (x < 0 || x > k) continue; 

            for (int j = k; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }

        return dp[k];
    }
};