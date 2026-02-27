class Solution {
    int findpow(int val,int n){
        int ans=1;
       for(int i=0;i<n;i++){
           ans*=val;
       }
       return ans;
        
    }
  public:
    int nthRoot(int n, int m) {
        if(n==0||m==0)return 0;
        if(m==1)return 1;
        int st=2,end=m/n;
        while(st<=end){
            int mid=st+(end-st)/2;
            int ans=findpow(mid,n);
            if(ans==m){
                return mid;
            }
            else if(ans>m){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return -1;
        
    }
};