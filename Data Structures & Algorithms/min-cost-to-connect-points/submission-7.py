class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def calculate(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])

        res = 0
        SIZE = len(points)
        unvisited = set(range(SIZE))
        min_dist = [float("inf")] * SIZE
        min_dist[0] = 0

        for _ in range(SIZE):
            small = float("inf")
            for i in unvisited:
                if min_dist[i] < small:
                    small = min_dist[i]
                    closest = i

            unvisited.remove(closest)
            res += min_dist[closest]

            for i in unvisited:
                min_dist[i] = min(min_dist[i], calculate(points[i], points[closest]))

        return res
