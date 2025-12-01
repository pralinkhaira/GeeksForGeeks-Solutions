class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0

class Solution:
    def cntPairs(self, arr, k):
        def insert(node, num):
            for i in range(19, -1, -1):
                bit = (num >> i) & 1
                if bit not in node.children:
                    node.children[bit] = TrieNode()
                node = node.children[bit]
                node.count += 1
        
        def countPairs(node, num, bit_pos):
            if node is None or bit_pos < 0:
                return 0
            
            num_bit = (num >> bit_pos) & 1
            k_bit = (k >> bit_pos) & 1
            
            if k_bit == 1:
                # We can take both bit values
                # Take same bit and count all
                res = 0
                if num_bit in node.children:
                    res += node.children[num_bit].count
                # Take different bit and continue
                if (1 - num_bit) in node.children:
                    res += countPairs(node.children[1 - num_bit], num, bit_pos - 1)
                return res
            else:
                # We must take same bit
                if num_bit in node.children:
                    return countPairs(node.children[num_bit], num, bit_pos - 1)
                return 0
        
        root = TrieNode()
        result = 0
        
        for num in arr:
            result += countPairs(root, num, 19)
            insert(root, num)
        
        return result