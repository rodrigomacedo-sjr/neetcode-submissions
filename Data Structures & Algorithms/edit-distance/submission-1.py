from functools import cache

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        size1 = len(word1)
        size2 = len(word2)

        @cache
        def dfs(i, j):
            res = 101

            if i >= size1:
                if j == size2:
                    return 0
                elif j < size2:
                    return size2 - j
            if j >= size2:
                if i == size1:
                    return 0
                elif i < size1:
                    return size1 - i

            # no op
            if word1[i] == word2[j]:
                res = min(dfs(i + 1, j + 1), res)

            # replace
            res = min(dfs(i + 1, j + 1) + 1, res)

            # remove
            res = min(dfs(i + 1, j) + 1, res)

            # insert
            res = min(dfs(i, j + 1) + 1, res)

            return res

        return dfs(0, 0)
