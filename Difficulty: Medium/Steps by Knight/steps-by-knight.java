class Solution {
    int rows[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int cols[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    public int minStepToReachTarget(int knightPos[], int targetPos[], int n) {
        Queue<Integer[]> q = new ArrayDeque<>();
        boolean[][] visited = new boolean[n+1][n+1];
        
        q.offer(new Integer[] {knightPos[0], knightPos[1]});
        int minSteps = 0;
        visited[knightPos[0]][knightPos[1]] = true;
        
        while(!q.isEmpty()) {
            int size = q.size();
            while(size > 0) {
                Integer[] curr = q.poll();
                if(curr[0] == targetPos[0] && curr[1] == targetPos[1]) return minSteps;
                for(int i=0;i<8;i++) {
                    int x = curr[0] + rows[i];
                    int y = curr[1] + cols[i];
                    if(x > 0 && x <= n && y > 0 && y <= n && !visited[x][y]) {
                        visited[x][y] = true;
                        q.offer(new Integer[] {x, y});
                    }
                }
                size--;
            }
            minSteps++;
        }
        return -1;
    }
}

