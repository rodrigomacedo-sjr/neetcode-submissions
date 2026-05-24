class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        SIZE = len(prices)
        buy = [0 for _ in range(SIZE + 2)]
        sell = [0 for _ in range(SIZE + 2)]
        for i in range(SIZE - 1, -1, -1):
            buy[i] = max(-prices[i] + sell[i + 1], buy[i + 1])
            sell[i] = max(+prices[i] + buy[i + 2], sell[i + 1])

        return buy[0]
