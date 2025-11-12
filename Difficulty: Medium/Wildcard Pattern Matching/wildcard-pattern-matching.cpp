class Solution {
  public:
    bool f(int i, int j, string &s, string& p, vector<vector<int>>& dp){
        if(i>=s.size() && j>=p.size()) return true;
        if(i>=s.size()){
            while(j<p.size()){
                if(p[j]!='*') return false;
                j++;
            }
            return true;
        }
        if(j>=p.size()) return false;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]){
            return dp[i][j] = f(i+1,j+1,s,p,dp);
        }
        if(p[j]=='?'){
            return dp[i][j] =  f(i+1,j+1,s,p,dp);
        }
        if(p[j]=='*'){
            return dp[i][j] =  f(i+1,j,s,p,dp) || f(i,j+1,s,p,dp);
        }
        return dp[i][j] =  false;
    }
    bool wildCard(string &txt, string &pat) {
        vector<vector<int>> dp(txt.size()+1, vector<int>(pat.size()+1, -1));
        return f(0, 0, txt, pat,dp);
    }
};