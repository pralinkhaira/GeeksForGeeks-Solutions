class Solution:
    def countAtMostK(self, arr, k):
        def atMostKDistinct(arr, k):
            count = {}
            left = 0
            result = 0
            
            for right in range(len(arr)):
                # Add the right element
                if arr[right] not in count:
                    count[arr[right]] = 0
                count[arr[right]] += 1
                
                # Shrink the window if we have more than k distinct elements
                while len(count) > k:
                    count[arr[left]] -= 1
                    if count[arr[left]] == 0:
                        del count[arr[left]]
                    left += 1
                
                # Add the count of all subarrays ending at right
                result += right - left + 1
            
            return result
        
        # Count subarrays with exactly k distinct - subarrays with k distinct
        return atMostKDistinct(arr, k)