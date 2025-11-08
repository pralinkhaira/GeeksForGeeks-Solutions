class Solution {
  public:
  int n,m;
  int solve(int i,int j,vector<vector<int>>& mat,vector<vector<vector<int>>>&dp,int k,int sum){
      if(i==n-1&&j==m-1){
          if(mat[i][j]+sum==k){
              return 1;
          }
      }
   
     
      if(i>=n||i<0||j>=m||j<0||sum>k)return 0;
       if(dp[i][j][sum]!=-1){
        return dp[i][j][sum];
    }
      int ans=0;
      ans+=solve(i+1,j,mat,dp,k,sum+mat[i][j]);
      ans+=solve(i,j+1,mat,dp,k,sum+mat[i][j]);
      return dp[i][j][sum]=ans;
  }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        n=mat.size();
        m=mat[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return solve(0,0,mat,dp,k,0);
    }
};