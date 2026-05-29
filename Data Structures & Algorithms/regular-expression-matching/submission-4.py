from functools import cache

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        size_s = len(s)
        size_p = len(p)

        @cache
        def dfs(i, j):
            if i == size_s and j == size_p:
                return True
            elif i == size_s:
                for k in range(j + 1, size_p, 2):
                    if p[k] != "*":
                        return False
                return (size_p - j) % 2 == 0
            elif j == size_p:
                return False

            if p[j] == "." or s[i] == p[j]:
                if j + 1 < size_p and p[j + 1] == "*":
                    if p[j] == "." or s[i] == p[j]:
                        if dfs(i + 1, j):
                            return True
                    if dfs(i, j + 2):
                        return True
                else:
                    if dfs(i + 1, j + 1):
                        return True
            elif j + 1 < size_p and p[j + 1] == "*":
                if dfs(i, j + 2):
                    return True

            return False
        return dfs(0, 0)