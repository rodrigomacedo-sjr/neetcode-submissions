class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        self.totalSum = 0

        for n in nums:
            self.totalSum += n
        
        if self.totalSum % 2 == 1: 
            return False

        self.target = self.totalSum / 2
        self.mem = {}

        return self.dfs(nums, 0, 0)

    def dfs(self, nums, idx, total):
        if (idx, total) in self.mem:
            return self.mem[(idx, total)]

        if total == self.target:
            self.mem[(idx, total)] = True
            return self.mem[(idx, total)]
        
        if total > self.target or idx >= len(nums):
            return False

        res = False
 
        res |= self.dfs(nums, idx + 1, total + nums[idx])
        res |= self.dfs(nums, idx + 1, total)

        self.mem[(idx, total)] = res
        return self.mem[(idx, total)]
        