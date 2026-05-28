from functools import cache

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        size1 = len(word1)
        size2 = len(word2)

        @cache
        def dfs(i, j):
            res = 101

            if i >= size1:
                    return size2 - j
            if j >= size2:
                    return size1 - i

            if word1[i] == word2[j]:
                res = min(dfs(i + 1, j + 1), res)

            for di, dj in [[1, 1], [1, 0], [0, 1]]:
                res = min(dfs(i + di, j + dj) + 1, res)

            return res

        return dfs(0, 0)
