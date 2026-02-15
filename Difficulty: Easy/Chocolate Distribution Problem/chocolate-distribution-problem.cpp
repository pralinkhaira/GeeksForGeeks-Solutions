class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n=a.size();
        if(m==0||n==0){
            return 0;
        }
        if(n<m){
            return -1;
        }
        sort(a.begin(), a.end());
        long long int mini=INT_MAX;
        int i=0;
        int j=m-1;
        
        while(j<n){
            long long int diff=a[j]-a[i];
            mini=min(mini,diff);
            i=i+1;
            j=j+1;
        }
        return mini;
    }
};