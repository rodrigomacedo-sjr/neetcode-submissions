from heapq import heappush, heappop
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        window = deque()
        for i in range(k):
            window.append(nums[i])
        res.append(max(window))

        for i in range(k, len(nums)):
            window.popleft()
            window.append(nums[i])
            res.append(max(window))

        return res
