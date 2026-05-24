def find(parents, curr):
    if parents[curr] == curr:
        return curr
    parents[curr] = find(parents, parents[curr])
    return parents[curr]

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        parents = [i for i in range(len(edges) + 1)]
        for a, b in edges:
            roota = find(parents, a)
            rootb = find(parents, b)
            if roota == rootb:
                return [a, b]
            else:
                parents[roota] = rootb
                find(parents, a)
        return [1, 2]