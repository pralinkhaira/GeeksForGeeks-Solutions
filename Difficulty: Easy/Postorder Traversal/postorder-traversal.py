class Solution:
    def postOrder(self, root):
        left = right = []
        if root.left:
            left = self.postOrder(root.left)
        if root.right:
            right = self.postOrder(root.right)
        return [*left, *right, root.data]