class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        int m=arr.size();
        int n=( 1 + sqrt(1+8*m) )/2;
        vector<int>ans(n);
        // res[0]+res[1]=arr[0]
        // res[0]+res[2]=arr[1]
        // res[1]+res[2]=arr[n-1]
        ans[0]=(arr[0]+arr[1]-arr[n-1])/2;
        for(int i=1; i<n; i++){
            ans[i]=arr[i-1]-ans[0];
        }
        return ans;
        
        
    }
};