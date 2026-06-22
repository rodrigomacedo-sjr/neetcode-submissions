from functools import cache

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1 = len(text1)
        l2 = len(text2)
        best = 0

        @cache
        def dfs(i, j):
            if i >= l1 or j >= l2:
                return 0
            a = 0
            if text1[i] == text2[j]:
                a = 1 + dfs(i + 1, j + 1)
            b = dfs(i, j + 1)
            c = dfs(i + 1, j)

            return max(a, b, c)
        
        return dfs(0, 0)
            
                

