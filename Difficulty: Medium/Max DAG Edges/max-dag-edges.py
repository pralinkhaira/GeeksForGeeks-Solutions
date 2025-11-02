class Solution:
    def maxEdgesToAdd(self, V, edges):
        # code here
        length = len(edges)
        total_edges = (V * (V - 1)) // 2
        additional_edges =total_edges-length
        return additional_edges