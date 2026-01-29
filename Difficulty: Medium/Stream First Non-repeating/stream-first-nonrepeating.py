from collections import deque
class Solution:
	def firstNonRepeating(self, s):
        q=deque()
        freq={}
        ans=[]
        for item in s:
            freq[item]=freq.get(item,0)+1
            if freq[item]==1:
                q.append(item)
            while q and freq[q[0]]>1:
                q.popleft()
            ans.append(q[0] if q else "#")
        return "".join(ans)