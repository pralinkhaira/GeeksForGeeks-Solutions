class Solution {
  public:
    int countStrings(int n) {
        // code here
        int x=1, y=2;
        for(int i=2; i<=n; i++){
            int z=x+y;
            x=y;
            y=z;
        }
        return y;
    }
};