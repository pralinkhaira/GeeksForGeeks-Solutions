class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        
        int n = (int)arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int s = 0;
        for(auto it:arr)
        {
            s+=it;
        }
        
        
        auto f = [&](int mid)->int{
            
            int curr = 0;
            int count = 1;
            for(int i=0;i<n;i++)
            {
                if((curr+arr[i])<=mid)
                {
                    curr+=arr[i];
                }
                else
                {
                    curr = arr[i];
                    count ++;
                }
            }
            return (count<=k);
        };
        int high  = s;
        int res = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(f(mid))
            {
                res = mid ;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return res;
    }
};