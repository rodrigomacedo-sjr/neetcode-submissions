from functools import cache

class Solution:
    def maxCoins(self, nums: List[int]) -> int:

        @cache
        def dfs(curr):
            if len(curr) == 1:
                return curr[0]
        
            best = -1
            for i in range(len(curr)):
                a = curr[i - 1] if (i - 1) >= 0 else 1
                b = curr[i + 1] if (i + 1) < len(curr) else 1
                res = a * curr[i] * b

                copy = curr[:i] + curr[i + 1:]

                best = max(best, res + dfs(copy))

            return best
        
        return dfs(tuple(nums))