class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int ans = 0;
        int f = 0,ff = 0, s = 0,sf = 0;
        int i = 0;
        for(int j = 0;j<arr.size();j++){
            if(arr[j] == f) ff++;
            else if(arr[j] == s) sf++;
            else if(f == 0){
                f = arr[j];
                ff++;
            }
            else if(s == 0) {
                s = arr[j];
                sf++;
            }
            else{
                while(i < j && (ff >= 1 && sf >= 1)){
                    if(arr[i] == f) ff--;
                    else if(arr[i] == s) sf--;
                    i++;
                    if(ff == 0 || sf == 0) ans = max(ans,j-i+1);
                }
                if(ff == 0){
                    ff++;
                    f = arr[j];
                }
                else if(sf == 0){
                    sf++;
                    s = arr[j];
                }
            }
            
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};