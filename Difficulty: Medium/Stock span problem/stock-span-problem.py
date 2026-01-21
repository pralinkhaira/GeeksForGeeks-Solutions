class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        result = []
        stack = []  # Stack to store (price, index) pairs
        
        for i in range(n):
            # Pop elements from stack while current price is >= stack top price
            while stack and stack[-1][0] <= arr[i]:
                stack.pop()
            
            # If stack is empty, span is i+1 (all days up to current)
            # Otherwise, span is distance from current index to previous higher element
            if not stack:
                span = i + 1
            else:
                span = i - stack[-1][1]
            
            result.append(span)
            stack.append((arr[i], i))
        
        return result