class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        SIZE = len(nums)
        output = []
        nums.sort()
        for idx, val in enumerate(nums):
            l, r = idx + 1, SIZE - 1

            while l < r:
                total = nums[l] + nums[r]

                if total < -val or l == idx:
                    l += 1
                    continue
                elif total > -val or r == idx:
                    r -= 1
                    continue
                elif total == -val:
                    output.append([val, nums[l], nums[r]])
                    l += 1

        return [list(item) for item in set(tuple(sub_list) for sub_list in output)]
