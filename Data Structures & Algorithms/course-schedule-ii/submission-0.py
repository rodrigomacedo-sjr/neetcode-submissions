def dfs(ans, adj, colors, curr):
    if colors.get(curr, 0) == 1:
        return True # problem
    if colors.get(curr, 0):
        return # been here
    
    colors[curr] = 1 # visiting

    for node, isAdj in enumerate(adj[curr]):
        if isAdj:
            if dfs(ans, adj, colors, node): 
                return True
    
    colors[curr] = 2 # visited
    ans.append(curr)
    

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[0 for i in range(numCourses)] for _ in range(numCourses)]
        for p in prerequisites:
            adj[p[0]][p[1]] = 1

        colors = {}

        ans = []

        for i in range(numCourses):
            if dfs(ans, adj, colors, i):
                return []

        return ans