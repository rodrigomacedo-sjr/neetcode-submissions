class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        SIZE = len(prices)
        buy_curr, buy_next, buy_next_next = 0, 0, 0
        sell_curr, sell_next = 0, 0
        for i in range(SIZE - 1, -1, -1):
            buy_curr = max(-prices[i] + sell_next, buy_next)
            sell_curr = max(+prices[i] + buy_next_next, sell_next)
            buy_next_next = buy_next
            buy_next = buy_curr
            sell_next = sell_curr

        return buy_curr
