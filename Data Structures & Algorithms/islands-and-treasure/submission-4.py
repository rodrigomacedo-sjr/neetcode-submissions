class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS = len(grid)
        COLS = len(grid[0])

        def bfs(i, j):
            q = []
            q.append((i, j, 0))
            visited = [[False for _ in range(COLS)] for _ in range(ROWS)]
            while q:
                i, j, d = q.pop(0)

                if i < 0 or i >= ROWS or j < 0 or j >= COLS or grid[i][j] == -1:
                    continue

                if visited[i][j]:
                    continue

                visited[i][j] = True
                if d < grid[i][j]:
                    grid[i][j] = d

                for di, dj in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                    q.append((i + di, j + dj, d + 1))

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    bfs(i, j)
