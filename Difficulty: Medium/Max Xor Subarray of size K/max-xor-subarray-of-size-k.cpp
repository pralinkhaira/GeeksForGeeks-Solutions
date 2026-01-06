class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currentXOR = 0;

        // Step 1: Compute XOR for the first window of size k
        for (int i = 0; i < k; i++) {
            currentXOR ^= arr[i];
        }

        int maxXOR = currentXOR;

        // Step 2: Slide the window from index k to n-1
        for (int i = k; i < n; i++) {
            // Update currentXOR:
            // ^ arr[i-k] removes the element leaving the window
            // ^ arr[i] adds the element entering the window
            currentXOR = currentXOR ^ arr[i - k] ^ arr[i];
            
            // Update the maximum result found so far
            maxXOR = max(maxXOR, currentXOR);
        }

        return maxXOR;
    }
};