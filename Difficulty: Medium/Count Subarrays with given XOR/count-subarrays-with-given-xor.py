class Solution:
    def subarrayXor(self, arr, k):
        prefix_xor = 0
        count = 0
        freq = {0:1}    # to handle subarray starting from 0
        
        for num in arr:
            prefix_xor ^= num 
            
            # If (prefix_xor ^ k) exists, add its frequency
            if (prefix_xor ^ k) in freq:
                count += freq[prefix_xor ^ k]
        
            # Update frequency map
            freq[prefix_xor] = freq.get(prefix_xor, 0) + 1
        
        return count