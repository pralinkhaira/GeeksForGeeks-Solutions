class Solution:
    def countSubs(self, s):
        # Use a set to store all distinct substrings
        distinct_substrings = set()
        
        # Generate all substrings
        n = len(s)
        for i in range(n):
            for j in range(i + 1, n + 1):
                distinct_substrings.add(s[i:j])
        
        # Return the count of distinct non-empty substrings
        return len(distinct_substrings)