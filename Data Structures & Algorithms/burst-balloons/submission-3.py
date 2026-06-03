from functools import cache

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        @cache
        def dfs(l, r):
            if (l + 1) == r:
                return 0
        
            best = -1
            for i in range(l + 1, r):
                coins = nums[l] * nums[i] * nums[r]
                total = coins + dfs(l, i) + dfs(i, r)
                best = max(best, total)

            return best
        
        nums = [1] + nums + [1]
        return dfs(0, len(nums) - 1)