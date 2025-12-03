class Solution:
    def tsp(self, cost):
        n = len(cost)
        ALL_VISITED = (1 << n) - 1

       
        dp = [[float('inf')] * n for _ in range(1 << n)]
        dp[1][0] = 0  

        for mask in range(1 << n):
            for u in range(n):
                if not (mask & (1 << u)):
                    continue
                for v in range(n):
                    if mask & (1 << v):
                        continue
                    new_mask = mask | (1 << v)
                    dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + cost[u][v])

      
        ans = float('inf')
        for i in range(n):
            ans = min(ans, dp[ALL_VISITED][i] + cost[i][0])

        return ans