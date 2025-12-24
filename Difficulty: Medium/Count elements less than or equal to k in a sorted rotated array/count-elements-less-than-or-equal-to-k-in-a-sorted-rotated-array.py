class Solution:
    def countLessEqual(self, arr, x):
        arr.sort()
        l, h = 0, len(arr) - 1
        ans = -1  # store the last index where arr[mid] <= x
        
        while l <= h:
            mid = l + (h - l) // 2
            if arr[mid] <= x:
                ans = mid
                l = mid + 1  # move right to find later occurrences
            else:
                h = mid - 1  # move left
        return ans + 1  # count = index + 1, or 0 if none found