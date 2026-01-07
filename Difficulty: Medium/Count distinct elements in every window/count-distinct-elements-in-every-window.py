class Solution:
    def countDistinct(self, arr, k):
        n = len(arr)
        ans = []
        freq = {}

        # First window
        for i in range(k):
            freq[arr[i]] = freq.get(arr[i], 0) + 1
        ans.append(len(freq))

        # Slide the window
        for i in range(k, n):
            # element going out
            out_elem = arr[i - k]
            freq[out_elem] -= 1
            if freq[out_elem] == 0:
                del freq[out_elem]

            # element coming in
            in_elem = arr[i]
            freq[in_elem] = freq.get(in_elem, 0) + 1

            ans.append(len(freq))

        return ans
