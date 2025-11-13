class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;

        boolean[][] dp = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;

        for (int i = 1; i <= n1; i++) {
            dp[i][0] = dp[i - 1][0] && s1.charAt(i - 1) == s3.charAt(i - 1);
        }

        for (int j = 1; j <= n2; j++) {
            dp[0][j] = dp[0][j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                char c = s3.charAt(i + j - 1);
                if (s1.charAt(i - 1) == c)
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (s2.charAt(j - 1) == c)
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }

        return dp[n1][n2];
    }
}