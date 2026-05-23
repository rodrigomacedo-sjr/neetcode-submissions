from functools import cache


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @cache
        def dfs(i, j):
            k = i + j
            if k >= len(s3):
                return i == len(s1) and j == len(s2)
            if i < len(s1) and s3[k] == s1[i]:
                if dfs(i + 1, j):
                    return True
            if j < len(s2) and s3[k] == s2[j]:
                if dfs(i, j + 1):
                    return True
            return False

        return dfs(0, 0)
