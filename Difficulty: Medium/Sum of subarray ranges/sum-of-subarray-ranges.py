class Solution:
    def subarrayRanges(self, arr):
        def sumSubarray(arr, isMax):
            stack = []
            n = len(arr)
            total = 0
            
            for i in range(n):
                if isMax:
                    # For maximum: pop smaller elements
                    while stack and arr[stack[-1]] < arr[i]:
                        idx = stack.pop()
                        left = idx - stack[-1] - 1 if stack else idx
                        right = i - idx - 1
                        total += arr[idx] * (left + 1) * (right + 1)
                else:
                    # For minimum: pop larger elements
                    while stack and arr[stack[-1]] > arr[i]:
                        idx = stack.pop()
                        left = idx - stack[-1] - 1 if stack else idx
                        right = i - idx - 1
                        total += arr[idx] * (left + 1) * (right + 1)
                
                stack.append(i)
            
            # Process remaining elements in stack
            while stack:
                idx = stack.pop()
                left = idx - stack[-1] - 1 if stack else idx
                right = n - idx - 1
                total += arr[idx] * (left + 1) * (right + 1)
            
            return total
        
        return sumSubarray(arr, True) - sumSubarray(arr, False)