class Solution:
    def generateIp(self, s):
        lth=len(s)
        ret=[]
        res=[]
        def dfs(ix=0):
            nonlocal s,lth,ret,res
            if ix>=lth:
                if len(res)!=4:
                    return
                ret.append('.'.join(list(map(str,res))))
                return
            if len(res)>4:
                return
            ve=int(s[ix])
            if not res:
                res=[ve]
                dfs(ix+1)
                res.pop()
            else:
                res+=[ve]
                dfs(ix+1)
                res.pop()
                if res[-1]>0:
                    cand=10*res[-1]+ve
                    if cand<256:
                        tmp=res[-1]
                        res=res[:-1]+[cand]
                        dfs(ix+1)
                        res[-1]=tmp
        dfs()
        return ret