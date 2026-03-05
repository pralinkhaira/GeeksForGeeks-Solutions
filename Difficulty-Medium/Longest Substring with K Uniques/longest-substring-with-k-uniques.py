class Solution:
    def longestKSubstr(self, s, k):
        n = len(s)
        max_len = -1
        char_count = {}
        start = 0

        for end in range(n):
            char_count[s[end]] = char_count.get(s[end], 0) + 1

            while len(char_count) > k:
                char_count[s[start]] -= 1
                if char_count[s[start]] == 0:
                    del char_count[s[start]]
                start += 1

            if len(char_count) == k:
                max_len = max(max_len, end - start + 1)

        return max_len