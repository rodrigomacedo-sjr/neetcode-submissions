class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        self.visited = {}
        self.count = {}
        self.max = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                self.dfs(grid, i, j, i * 2 + j * 3)
        
        return self.max

    def dfs(self, grid, row, col, color):
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]):
            return

        if not grid[row][col]:
            return

        if self.visited.get((row, col), False):
            return

        self.visited[(row, col)] = True
        self.count[color] = self.count.get(color, 0) + 1
        
        self.max = max(self.max, self.count[color])

        for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            self.dfs(grid, row + dr, col + dc, color)


