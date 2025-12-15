class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        int totalEven = 0, totalOdd = 0;

        for (int i = 0; i < n; i++) {
            if (i & 1) totalOdd += arr[i];
            else totalEven += arr[i];
        }

        int prefEven = 0, prefOdd = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (i & 1) totalOdd -= arr[i];
            else totalEven -= arr[i];

            int newEven = prefEven + totalOdd;
            int newOdd  = prefOdd  + totalEven;

            if (newEven == newOdd) ans++;

            if (i & 1) prefOdd += arr[i];
            else prefEven += arr[i];
        }

        return ans;
    }
};