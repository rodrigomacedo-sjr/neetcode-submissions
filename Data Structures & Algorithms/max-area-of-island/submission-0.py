class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.ROWS = len(grid)
        self.COLS = len(grid[0])
        self.max = 0
        self.colors = {}
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        self.visited = {}
        curr = 0
        for i in range(self.ROWS):
            for j in range(self.COLS):
                self.dfs(grid, i, j, curr)
                curr += 1
        return self.max
        
    def dfs(self, grid, r, c, color):
        if r >= self.ROWS or r < 0 or c >= self.COLS or c < 0:
            return

        if not grid[r][c] or self.visited.get((r,c), False): 
            return
        
        self.visited[(r,c)] = True
        if self.colors.get(color, False):
            self.colors[color] += 1
        else:
            self.colors[color] = 1

        self.max = max(self.max, self.colors[color])

        for x, y in self.directions:
            self.dfs(grid, r + x, c + y, color)

