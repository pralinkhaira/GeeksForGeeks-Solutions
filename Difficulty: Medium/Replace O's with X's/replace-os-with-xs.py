class Solution:
    def fill(self, grid):
        # Code here
        m, n = len(grid), len(grid[0])
        mat = [['-1']*n for _ in range(m)]
        q = []
        vis = set()
        for i in range(m):
            for j in range(n):
                if (i == 0 or i == m-1 or j == 0 or j == n-1) and grid[i][j] == 'O':
                    q.append((i, j))
                    grid[i][j] = '2'
                    vis.add((i, j))
        
                
      
        while(q):
            i, j = q.pop(0)
            for r, c in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
                nr, nc = r + i, c + j
                if 0 <= nr < m and 0 <= nc < n and (nr, nc) not in vis and grid[nr][nc] == 'O':
                    grid[nr][nc] = '1'
                    q.append((nr, nc))
                    vis.add((nr, nc))
      
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 'O':
                    grid[i][j] = 'X'
                
                elif grid[i][j] == '1':
                    grid[i][j] = 'O'
                elif grid[i][j] == '2':
                    grid[i][j] = 'O'
                    
        
        return grid