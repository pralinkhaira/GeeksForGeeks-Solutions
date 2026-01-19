from collections import deque
class Solution:
    def removeKdig(self, s, k):
        dq=deque()
        for digit in s:
            while dq and k>0 and digit<dq[-1]:
                dq.pop()
                k-=1
            dq.append(digit)
        while k:
            dq.pop()
            k-=1
        while dq and dq[0]=="0":
            dq.popleft()
        return "".join(dq) if dq else 0