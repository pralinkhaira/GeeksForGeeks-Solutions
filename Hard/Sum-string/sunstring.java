class Solution {
      public boolean isSumString(String s) {
        int ans=0;
        int n=s.length();
        int[]a=new int[n];
        if(n<3)return false;
        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            a[i]=ch-48;
        }
        int m=n/3;
        int pre=0;
        int cnt1=0;
        for(int i=0;i<n;i++){
             pre=pre*10+a[i];
            cnt1++;
            int next=0;
            int cnt2=0;
            for(int j=i+1;j<n;j++){
                if(next==0&&a[j]==0)break;
                cnt2++;
                next=next*10+a[j];
                int nnext=0;
                int cnt3=0;
                for(int k=j+1;k<n;k++){
                    if(nnext==0&&a[k]==0)break;
                    nnext=nnext*10+a[k];
                    if(pre+next==nnext){
                        ans++;
                        pre=next;
                        next=nnext;
                        nnext=0;
                        if(k==n-1)return true;
                    }
                    else if(nnext>next+pre)break;
                }
            }
        }
        return false;
        
    }
}