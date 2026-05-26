class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS = len(grid)
        COLS = len(grid[0])

        def bfs(i, j):
            q = []
            q.append((i, j, 0))
            visited = [[False for _ in range(COLS)] for _ in range(ROWS)]
            while q:
                # Pop queue
                i, j, d = q[0]
                q.pop(0)

                # Skip invalid
                if i < 0 or i >= ROWS or j < 0 or j >= COLS or grid[i][j] == -1:
                    continue

                # Skip visited
                if visited[i][j]:
                    continue

                # Visit
                visited[i][j] = True
                if d < grid[i][j]:
                    grid[i][j] = d

                # Enqueue neighbours
                for x, y in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                    q.append((i + x, j + y, d + 1))
        print(ROWS)
        print(COLS)

        # BFS from treasures
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    bfs(i, j)
