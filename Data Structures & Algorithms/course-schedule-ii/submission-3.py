class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        self.adj = [[] for _ in range(numCourses)]
        for p in prerequisites:
            self.adj[p[0]].append(p[1])

        self.colors = [0] * numCourses

        self.ans = []

        for i in range(numCourses):
            if self.dfs(i):
                return []

        return self.ans
    def dfs(self, curr):
        if self.colors[curr] == 1:
            return True
        if self.colors[curr]:
            return False
        
        self.colors[curr] = 1

        for prereq in self.adj[curr]:
            if self.dfs(prereq): 
                return True
        
        self.colors[curr] = 2
        self.ans.append(curr)