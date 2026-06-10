class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        if len(nums) < 2:
            return [nums[0]]
        c1 = [nums[0], 0]
        c2 = [nums[1], 0]
        for i in range(len(nums)):
            if nums[i] == c1[0]:
                c1[1] += 1
                continue
            elif nums[i] == c2[0]:
                c2[1] += 1
                continue

            if c1[1] > 0:
                c1[1] -= 1
            elif c2[1] > 0:
                c1[0] = nums[i]

            if c2[1] > 0:
                c2[1] -= 1
            else:
                c2[0] = nums[i]
        
        c1[1] = 0
        c2[1] = 0
        for n in nums:
            if n == c1[0]:
                c1[1] += 1
            elif n == c2[0]:
                c2[1] += 1

        ans = []
        if c1[1] > len(nums) // 3:
            ans.append(c1[0])
        if c2[1] > len(nums) // 3:
            ans.append(c2[0])
        return ans
        