class Solution {
    int minCost(int[] height) {
        // code here
        int n = height.length;
        int dp[] = new int[n+1];
        
        for(int i=n-2; i>=0; i--){
            int step1 = Math.abs(height[i] - height[i+1]) + dp[i+1];
            int step2 = i + 2 >= n ? Integer.MAX_VALUE : Math.abs(height[i] - height[i+2]) + dp[i+2];
            dp[i] = Math.min(step1, step2);
        }
        
        return dp[0];
    }
}