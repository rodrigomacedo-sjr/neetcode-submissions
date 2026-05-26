from collections import deque

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS = len(grid)
        COLS = len(grid[0])

        q = deque()

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    q.append((i, j, 0))

        visited = [[False for _ in range(COLS)] for _ in range(ROWS)]
        while q:
            i, j, d = q.popleft()


            visited[i][j] = True
            if d < grid[i][j]:
                grid[i][j] = d

            for di, dj in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                ni, nj = i + di, j + dj
                if ni < 0 or ni >= ROWS or nj < 0 or nj >= COLS:
                    continue
    
                if visited[ni][nj] or grid[ni][nj] == -1:
                    continue
                q.append((ni, nj, d + 1))
