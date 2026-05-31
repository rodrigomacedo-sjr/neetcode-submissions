from heapq import heappush, heappop

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        h = []

        for i in range(len(nums)):
            heappush(h, (-nums[i], i))

            if i >= k - 1:
                nxt, idx = h[0]
                while idx <= (i - k):
                    heappop(h)
                    nxt, idx = h[0]
                res.append(-nxt)

        return res
