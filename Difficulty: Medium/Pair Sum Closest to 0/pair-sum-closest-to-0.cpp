class Solution {
  public:
    int closestToZero(int arr[], int n)
        {
            sort(arr,arr+n);
            int i=0,j=n-1;
            int pos=INT_MAX,neg=INT_MIN;
            while(i<j){
                int sum=arr[i]+arr[j];
                if(sum==0) return sum;
                else if(sum<0) {
                    neg=max(neg,sum);
                    i++;
                }
                else {
                    pos=min(pos,sum);
                    j--;
                }
            }
            pos=abs(pos);
            neg= (neg==INT_MIN ? INT_MAX: abs(neg));
            if(pos>neg) return -neg;
            return pos;
        }
};