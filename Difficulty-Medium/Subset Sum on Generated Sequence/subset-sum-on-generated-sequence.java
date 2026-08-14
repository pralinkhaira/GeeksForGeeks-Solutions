class Solution {
    public boolean isPossible(int[] arr, int s, int x) {
        int n = arr.length;
        long[] dp = new long[n + 1];

        dp[0] = s;
        long sum = s;

        for(int i = 1; i <= n; i++) {
            dp[i] = sum + arr[i - 1];
            sum += dp[i];
        }

        long target = x;

        for(int i = n; i >= 0; i--) {
            if(dp[i] <= target) {
                target -= dp[i];
            }

            if(target == 0) {
                return true;
            }
        }

        return false;
    }
}