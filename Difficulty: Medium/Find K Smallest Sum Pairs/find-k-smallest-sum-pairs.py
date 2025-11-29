import heapq

class Solution:
    def kSmallestPair(self, arr1, arr2, k):
        # Min heap stores (sum, i, j) where i is index in arr1, j is index in arr2
        min_heap = [(arr1[0] + arr2[0], 0, 0)]
        visited = {(0, 0)}
        result = []
        
        while len(result) < k and min_heap:
            current_sum, i, j = heapq.heappop(min_heap)
            result.append([arr1[i], arr2[j]])
            
            # Add next possible pairs
            # Move to next element in arr1
            if i + 1 < len(arr1) and (i + 1, j) not in visited:
                heapq.heappush(min_heap, (arr1[i + 1] + arr2[j], i + 1, j))
                visited.add((i + 1, j))
            
            # Move to next element in arr2
            if j + 1 < len(arr2) and (i, j + 1) not in visited:
                heapq.heappush(min_heap, (arr1[i] + arr2[j + 1], i, j + 1))
                visited.add((i, j + 1))
        
        return result