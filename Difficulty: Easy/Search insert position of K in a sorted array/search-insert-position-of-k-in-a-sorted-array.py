class Solution:
     def searchInsertK(self, arr, k):
          # code here
          n = len(arr)
          for i in range(n):
               if arr[i] == k or arr[i] > k:
                    return i
          return n