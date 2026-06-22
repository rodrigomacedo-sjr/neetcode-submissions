from functools import cache

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1, l2 = len(text1), len(text2)

        @cache
        def dfs(i, j):
            if i >= l1 or j >= l2:
                return 0
            a = 0
            if text1[i] == text2[j]:
                a = 1 + dfs(i + 1, j + 1)

            return max(a, dfs(i + 1, j), dfs(i, j + 1))
        
        return dfs(0, 0)
            
                

