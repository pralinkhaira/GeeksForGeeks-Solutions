class Solution:    
    def printNos(self, n):
        if n == 0:
            return
        self.printNos(n-1)
        print(n, end=" ")