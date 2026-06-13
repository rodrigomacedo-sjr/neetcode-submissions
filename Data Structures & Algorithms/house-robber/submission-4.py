class Solution:
    def rob(self, nums: List[int]) -> int:
        n, nn = 0, 0
        for i in range(len(nums) - 1, -1, -1):
            c = max(nums[i] + nn, n)
            nn = n
            n = c
        return c
