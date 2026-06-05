from functools import reduce

class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        SIZE = len(target)
        ans = [False, False, False]
        for trip in triplets:
            if reduce(lambda x, y: x or y, [trip[i] > target[i] for i in range(SIZE)]):
                continue

            for i in range(SIZE):
                if trip[i] == target[i]:
                    ans[i] = True

        return reduce(lambda x, y: x and y, ans)
                
