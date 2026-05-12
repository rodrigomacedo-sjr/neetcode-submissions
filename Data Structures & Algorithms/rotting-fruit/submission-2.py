class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.time = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == 2):
                    self.time[(i, j)] = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (grid[i][j] == 2) and self.time[(i, j)] == 0:
                    self.dfs(grid, i, j)

        big = 0
        for _, v in self.time.items():
            if v > big:
                big = v

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    return -1
        return big

    def dfs(self, grid, r, c):
        for i, j in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
            nr = r + i
            nc = c + j
            if nr < 0 or nr >= len(grid) or nc < 0 or nc >= len(grid[0]):
                continue
            if grid[nr][nc] == 0:
                continue
            if (nr, nc) not in self.time or self.time[(nr, nc)] > self.time[(r, c)] + 1:
                grid[nr][nc] = 2
                self.time[(nr, nc)] = self.time[(r, c)] + 1
                self.dfs(grid, nr, nc)
