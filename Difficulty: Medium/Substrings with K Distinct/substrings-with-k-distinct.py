class Solution:
    def countSubstr(self, s, k):
        def atMostKDistinct(s, k):
            """Count substrings with at most k distinct characters"""
            count = 0
            char_freq = {}
            left = 0
            
            for right in range(len(s)):
                # Add the right character
                char_freq[s[right]] = char_freq.get(s[right], 0) + 1
                
                # Shrink window if we have more than k distinct characters
                while len(char_freq) > k:
                    char_freq[s[left]] -= 1
                    if char_freq[s[left]] == 0:
                        del char_freq[s[left]]
                    left += 1
                
                # All substrings ending at right and starting from [left, right]
                # have at most k distinct characters
                count += right - left + 1
            
            return count
        
        # Substrings with exactly k distinct = at most k - at most (k-1)
        return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1)