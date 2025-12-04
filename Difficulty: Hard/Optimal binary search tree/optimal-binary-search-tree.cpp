class Solution {
  public:
    int dp[101][101];
    int recur(int l,int r,vector<pair<int,int>>&arr){
        if(l==r)
            return arr[l].second;
        if(l>r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        int ans=INT_MAX,total_freq=0;
        for(int i=l;i<=r;i++){
            int cans=recur(l,i-1,arr)+recur(i+1,r,arr);
            ans=min(ans,cans);
            total_freq+=arr[i].second;
        }
        return dp[l][r]=ans+total_freq;
    }
    int minCost(vector<int> &keys, vector<int> &freq) {
        // code here
        int n=keys.size();
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++)
            arr[i]={keys[i],freq[i]};
        // sort(arr.begin(),arr.end());
        memset(dp,-1,sizeof(dp));
        return recur(0,n-1,arr);
    }
};