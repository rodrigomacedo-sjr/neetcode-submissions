from functools import cache

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 == 1: 
            return False

        target = sum(nums) / 2

        @cache
        def dfs(idx, total):
            if total == target:
                return True
            
            if total > target or idx >= len(nums):
                return False

            return dfs(idx + 1, total + nums[idx]) or dfs(idx + 1, total)
        
        return dfs(0, 0)
        