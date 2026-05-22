class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def calculateCost(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])

        SIZE = len(points)
        done = {}
        done[0] = True

        vertices = set()

        res = 0

        for i in range(SIZE):
            for j in range(SIZE):
                cost = calculateCost(points[i], points[j])
                vertices.add((cost, i, j))
                vertices.add((cost, j, i))

        vertices = list(vertices)
        vertices.sort()

        while len(done) < SIZE:
            for v in vertices:
                if not done.get(v[1], False) ^ done.get(v[2], False):
                    continue
                done[v[1]] = True
                done[v[2]] = True
                res += v[0]
                break
        
        return res
        
        