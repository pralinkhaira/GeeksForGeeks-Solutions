class Solution: 
    def selectionSort(self, arr):
        n = len(arr)
        for i in range(0,n):
            min = i
            for j in range(i+1,n):
                if arr[j] < arr[min]:
                    min = j
                
            arr[i], arr[min] = arr[min], arr[i]   #code here