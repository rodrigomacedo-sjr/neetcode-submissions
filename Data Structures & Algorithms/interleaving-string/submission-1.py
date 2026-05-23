from functools import cache

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s3) != len(s1) + len(s2):
            return False

        @cache
        def dfs(idx1, idx2, last, balance):
            idx3 = idx1 + idx2
            p1 = False
            p2 = False
            if idx3 >= len(s3):
                return abs(balance) <= 2
            if idx1 < len(s1) and s3[idx3] == s1[idx1]:
                change = last != 1
                p1 = dfs(idx1 + 1, idx2, 1, balance + change)
            if idx2 < len(s2) and s3[idx3] == s2[idx2]:
                change = last != 2
                p2 = dfs(idx1, idx2 + 1, 2, balance - change)
            return p1 or p2

        return dfs(0, 0, 1, 0)
            