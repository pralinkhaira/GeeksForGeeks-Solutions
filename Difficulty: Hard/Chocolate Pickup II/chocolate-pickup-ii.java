class Solution {
    Map<String, Integer> dp = new HashMap<>();
    int helper(int[][] mat, int r1, int c1, int r2, int c2, int n) {
        if(r1 >= n || r2 >= n || c1 >= n || c2 >= n ||
            mat[r1][c1] == -1 || mat[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
        if(r1 == n-1 && c1 == n-1)
            return mat[r1][c1];
        String key = r1+" : "+c1+" : "+r2+" : "+c2;
        if(dp.containsKey(key))
            return dp.get(key);
        
        int totalCoc = 0;
        if(r1 == r2 && c1 == c2) {
            totalCoc += mat[r1][c1];
        } else {
            totalCoc += mat[r1][c1] + mat[r2][c2];
        }
        int d1 = helper(mat, r1+1, c1, r2+1, c2, n),
            d2 = helper(mat, r1, c1+1, r2, c2+1, n),
            d3 = helper(mat, r1+1, c1, r2, c2+1, n),
            d4 = helper(mat, r1, c1+1, r2+1, c2, n);
        
        totalCoc += Math.max(d1, Math.max(d2, Math.max(d3, d4)));
        dp.put(key, totalCoc);
        return totalCoc;
    }
    public int chocolatePickup(int[][] mat) {
        int n=mat.length;
        if(mat[n-1][n-1] == -1)
            return 0;
        int ans = helper(mat, 0, 0, 0, 0, n);
        return Math.max(0, ans);
    }
}