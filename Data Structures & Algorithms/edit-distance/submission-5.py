class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        size1 = len(word1)
        size2 = len(word2)

        dp = [[float('inf') for _ in range(size2 + 1)] for _ in range(size1 + 1)]

        for i in range(size1):
            dp[i][size2] = size1 - i

        for j in range(size2):
            dp[size1][j] = size2 - j
        
        dp[size1][size2] = 0

        for i in range(size1 - 1, -1, -1):
            for j in range(size2 - 1, -1, -1):
                if i < size1 and j < size2 and word1[i] == word2[j]:
                    dp[i][j] = min(dp[i][j], dp[i + 1][j + 1])

                for di, dj in [[1, 1], [1, 0], [0, 1]]:
                    dp[i][j] = min(dp[i][j], dp[i + di][j + dj] + 1)

        return dp[0][0]