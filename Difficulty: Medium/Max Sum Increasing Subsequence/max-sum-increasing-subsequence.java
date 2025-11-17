class Solution {
    public int solve(int prev, int curr,int[] nums,int[][] dp){
        if(curr==nums.length)return 0;
        if(prev!=-1 && dp[prev][curr]!=0)return dp[prev][curr];

        int take=0;
        if(prev==-1 || nums[prev]<nums[curr]){
            take=nums[curr]+solve(curr,curr+1,nums,dp);
        }

        int notake=solve(prev,curr+1,nums,dp);

        if(prev!=-1){
            dp[prev][curr]=Math.max(take,notake);
        }
        return Math.max(take,notake);
    }
    public int maxSumIS(int nums[]) {
        int n=nums.length;
        int[][] dp=new int[n+1][n+1];
        return solve(-1,0,nums,dp);
    }
}