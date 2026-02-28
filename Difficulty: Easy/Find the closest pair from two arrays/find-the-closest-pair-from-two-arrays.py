class Solution:
    def findClosestPair(self, arr1, arr2, x):
        min_diff = abs(arr1[0] + arr2[0] - x)
        pair = (arr1[0], arr2[0])
        m, n = len(arr1), len(arr2)
        i, j = 0, n - 1
        while i < m and j >= 0:
            sumi = arr1[i] + arr2[j]
            if (d := abs(sumi - x)) < min_diff:
                min_diff = d
                pair = (arr1[i], arr2[j])
            if sumi > x:
                j -= 1
            else:
                i += 1
        return pair