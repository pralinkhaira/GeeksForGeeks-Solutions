class Solution:
    def findMedian(self, root):
        def inorder(node, arr):
            if not node:
                return
            inorder(node.left, arr)
            arr.append(node.data)
            inorder(node.right, arr)
        
        arr = []
        inorder(root, arr)
        n = len(arr)
        
        # For 1-based indexing in the problem statement
        if n % 2 == 1:
            return arr[n // 2]   # (n+1)/2 (1-based) → n//2 (0-based)
        else:
            return arr[(n // 2) - 1]  # V(n/2) (1-based) → (n//2 - 1) (0-based)