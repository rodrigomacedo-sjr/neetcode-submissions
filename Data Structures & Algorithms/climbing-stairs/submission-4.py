from functools import cache

class Solution:
    @cache
    def climbStairs(self, n: int) -> int:
        ans = [1 for _ in range(n + 1)]
        ans[1] = 2 

        for i in range(2, n):
            ans[i] = ans[i - 1] + ans[i - 2]
        return ans[n - 1]