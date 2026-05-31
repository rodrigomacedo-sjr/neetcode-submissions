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

            l = i - k 
            nxt, idx = h[0]
            print(h[0])
            while idx <= l:
                heappop(h)
                print("popping")
                print(h[0])
                nxt, idx = h[0]
            print("l: ", l)
            print("res +=: ", -nxt)
            res.append(-nxt)

        return res
