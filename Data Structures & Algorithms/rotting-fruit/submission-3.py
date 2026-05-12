class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        time = 0
        fresh = 0
        q = []

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))
        
        while q and fresh > 0:
            directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
            size = len(q)
            for _ in range(size):
                i, j = q[0]
                q.pop(0)
                for rd, cd in directions:
                    if (i + rd) not in range(ROWS) or (j + cd) not in range(COLS):
                        continue
                    if (grid[i + rd][j + cd] == 1):
                        q.append((i + rd, j + cd))
                        grid[i + rd][j + cd] = 3
                        fresh -= 1
            time += 1

        if fresh > 0: return -1
        
        return time

