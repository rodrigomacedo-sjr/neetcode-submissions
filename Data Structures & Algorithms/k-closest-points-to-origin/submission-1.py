from heapq import heappush, heappop


def calculateDistance(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** (1 / 2)


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        max_heap = []
        origin = [0, 0]
        for idx, point in enumerate(points):
            heappush(max_heap, (-calculateDistance(origin, point), idx))
            if len(max_heap) > k:
                heappop(max_heap)

        ans = []
        while max_heap:
            top = heappop(max_heap)
            ans.append(points[top[1]])

        return ans
