class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def calculateCost(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])
        
        def find(i):
            if parents[i] == i:
                return i
            parents[i] = find(parents[i])
            return parents[i]

        SIZE = len(points)
        parents = [i for i in range(SIZE)]
        edges = 0
        vertices = set()
        res = 0

        for i in range(SIZE):
            for j in range(i + 1, SIZE):
                cost = calculateCost(points[i], points[j])
                vertices.add((cost, i, j))

        vertices = list(vertices)
        vertices.sort()

        for v in vertices:
            root1 = find(v[1])
            root2 = find(v[2])
            if root1 == root2:
                continue
            parents[root1] = root2
            res += v[0]
            edges += 1
            if edges == SIZE - 1: break
        
        return res
        
        