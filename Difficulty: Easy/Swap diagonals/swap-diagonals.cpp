class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        for(int i = 0; i < mat.size(); i++) swap(mat[i][i], mat[i][mat.size() - i - 1]);
    }
};