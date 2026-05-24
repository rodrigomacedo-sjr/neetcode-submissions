from functools import cache

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        @cache
        def dfs(i, wallet):
            if i >= len(prices):
                return 0
            sell, buy = 0, 0
            if wallet != -1:
                profit = prices[i] - wallet
                sell = profit + dfs(i + 2, -1)
            else:
                buy = dfs(i + 1, prices[i])
            nothing = dfs(i + 1, wallet)

            curr_max = max(sell, buy, nothing)
            return curr_max

        return dfs(0, -1)