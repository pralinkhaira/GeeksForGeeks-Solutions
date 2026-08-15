class Solution {
    public:
      int countWithout(int n, int d) {
          string s = to_string(n);

          long long dp[2][2] = {};

          dp[1][0] = 1;

          for (char current : s) {
              long long next[2][2] = {};

              for (int tight = 0; tight <= 1; ++tight) {
                  for (int started = 0; started <= 1; ++started) {
                      if (dp[tight][started] == 0) {
                          continue;
                      }

                      int limit = tight ? current - '0' : 9;

                      for (int digit = 0; digit <= limit; ++digit) {
                          bool nextStarted = started || digit != 0;

                          if (nextStarted && digit == d) {
                              continue;
                          }

                          int nextTight = tight && (digit == limit);

                          next[nextTight][nextStarted] += dp[tight][started];
                      }
                  }
              }

              for (int tight = 0; tight <= 1; ++tight) {
                  for (int started = 0; started <= 1; ++started) {
                      dp[tight][started] = next[tight][started];
                  }
              }
          }
          return static_cast<int>(dp[0][1] + dp[1][1]);
      }
  };