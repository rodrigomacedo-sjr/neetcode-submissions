from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        md = deque()

        for i in range(len(nums)):
            if md and md[0] == i - k:
                md.popleft()

            while md and nums[md[-1]] < nums[i]:
                md.pop()

            md.append(i)

            if i >= k - 1:
                res.append(nums[md[0]])

        return res
