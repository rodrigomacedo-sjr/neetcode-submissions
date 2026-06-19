class Solution:
    def rob(self, nums: List[int]) -> int:
        p, pp = 0, 0
        for i in range(len(nums) - 1, -1, -1):
            c = max(nums[i] + pp, p)
            pp = p
            p = c
        return c