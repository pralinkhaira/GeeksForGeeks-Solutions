class Solution:
    def transpose(self, mat):
        # code here
        r=[[mat[j][i] for j in range(len(mat))]for i in range(len(mat[0]))]
        return r