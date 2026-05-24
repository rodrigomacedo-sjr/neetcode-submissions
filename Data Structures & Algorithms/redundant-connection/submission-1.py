class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parents = [i for i in range(len(edges) + 1)]

        def find(a):
            if parents[a] == a:
                return a
            parents[a] = find(parents[a])
            return parents[a]

        for a, b in edges:
            roota = find(a)
            rootb = find(b)
            if roota == rootb:
                return [a, b]
            parents[roota] = rootb