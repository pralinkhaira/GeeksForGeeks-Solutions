class Solution {
  public:
    int solve(int i , int j , vector<int>&arr,int player,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(player==0){
            int op1 = arr[i] + solve(i+1,j,arr,1,dp);
            int op2 = arr[j] + solve(i,j-1,arr,1,dp);
            return dp[i][j] = max(op1,op2);
        }
        else{
            int op1 = solve(i+1,j,arr,0,dp);
            int op2 = solve(i,j-1,arr,0,dp);
            return dp[i][j] = min(op1,op2);
        }
    }
    int maximumAmount(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,arr,0,dp);
    }
};