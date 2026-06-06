from functools import cache
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:

        @cache
        def dfs(curr, last):
            if curr == 0:
                return 1

            res = 0
            for i in range(last, len(coins)):
                if curr - coins[i] < 0:
                    continue
                
                res += dfs(curr - coins[i], i)
            return res
        
        return dfs(amount, 0)
