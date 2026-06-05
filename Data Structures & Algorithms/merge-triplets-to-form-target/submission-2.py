class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        ans = [False, False, False]
        for trip in triplets:
            if any([trip[i] > target[i] for i in range(3)]):
                continue

            for i in range(3):
                if trip[i] == target[i]:
                    ans[i] = True

        return all(ans)