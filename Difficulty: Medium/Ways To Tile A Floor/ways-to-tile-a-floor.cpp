class Solution {
  public:
    int numberOfWays(int n) {
        if(n == 0 || n == 1)return 1;
        if(n < 0)return 0;
        int ans = 2 * numberOfWays(n - 2) + numberOfWays(n - 3);
        return ans;
    }
};