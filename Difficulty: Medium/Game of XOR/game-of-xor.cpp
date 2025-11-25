class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n= arr.size();
        if(n%2==0){
            return 0;
        }
        int x=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                x^=arr[i];
            }
        }
        return x;
    }
};