from collections import deque
class Solution:
    def inorder(self,root,dq):
        if root:
            self.inorder(root.left,dq)
            if len(dq)<self.k:
                dq.append(root.data)
            else:
                if self.target-dq[0]>root.data-self.target:
                    dq.popleft()
                    dq.append(root.data)
                else:
                    return
            self.inorder(root.right,dq)
    
    def getKClosest(self, root, target, k):
        self.k=k
        self.target=target
        dq=deque()
        self.inorder(root,dq)
        return list(dq)