def dfs(ans, adj, colors, curr):
    if colors[curr] == 1:
        return True
    if colors[curr]:
        return False
    
    colors[curr] = 1

    for node in adj[curr]:
        if dfs(ans, adj, colors, node): 
            return True
    
    colors[curr] = 2
    ans.append(curr)
    

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj = [[] for _ in range(numCourses)]
        for p in prerequisites:
            adj[p[0]].append(p[1])

        colors = [0] * numCourses

        ans = []

        for i in range(numCourses):
            if dfs(ans, adj, colors, i):
                return []

        return ans