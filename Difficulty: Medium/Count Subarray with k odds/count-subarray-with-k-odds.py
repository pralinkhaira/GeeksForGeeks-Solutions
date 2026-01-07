class Solution:
    def countSubarrays(self, arr, k):
        # Use a hash map to store the count of prefix sums
        # We'll track how many times we've seen each count of odd numbers
        count = 0
        odd_count = 0
        prefix_count = {0: 1}  # Initialize with 0 odds count
        
        for num in arr:
            # If the number is odd, increment odd_count
            if num % 2 == 1:
                odd_count += 1
            
            # Check if there's a prefix with (odd_count - k) odds
            # This means the subarray between that prefix and current position has exactly k odds
            if odd_count - k in prefix_count:
                count += prefix_count[odd_count - k]
            
            # Add current odd_count to the map
            if odd_count not in prefix_count:
                prefix_count[odd_count] = 0
            prefix_count[odd_count] += 1
        
        return count