class Solution {
public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        int idx=0;
        int ans=1;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[idx]){
                count=i-idx;
                idx=i;
            }
            else if(arr[i]>arr[idx]){
                count=i+1;
                idx=i;
            }
            else{
                count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};