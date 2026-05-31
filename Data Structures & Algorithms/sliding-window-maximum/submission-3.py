from heapq import heappush, heappop

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res = []
        h = []
        for i in range(k):
            heappush(h, (-nums[i], i))
        res.append(-h[0][0])

        for i in range(k, len(nums)):
            heappush(h, (-nums[i], i))

            nxt, idx = h[0]
            while idx <= (i - k):
                heappop(h)
                nxt, idx = h[0]
            res.append(-nxt)

        return res
