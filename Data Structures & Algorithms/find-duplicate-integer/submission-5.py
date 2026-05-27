class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        for n in nums:
            abs_n = abs(n)
            if nums[abs_n - 1] < 0:
                return abs_n
            nums[abs_n - 1] = -abs(nums[abs_n - 1])