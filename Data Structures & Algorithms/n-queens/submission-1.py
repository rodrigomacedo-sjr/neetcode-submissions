class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [["." for _ in range(n)] for _ in range(n)]
        ans = []
        used_cols = [False for _ in range(n)]

        def check(curr, i, j):
            if used_cols[j]:
                return False

            for di, dj in [[-1, -1], [-1, 1], [1, -1], [1, 1]]:
                ci, cj = i, j
                while ci < n and cj < n and ci >= 0 and cj >= 0:
                    if curr[ci][cj] == "Q":
                        return False
                    ci += di
                    cj += dj
            return True

        def dfs(curr, idx):
            if idx == n:
                new_ans = []
                for row in curr:
                    new_ans.append("".join(row))
                ans.append(new_ans)
                return
                
            for j in range(n): # cols
                if curr[idx][j] != "Q" and check(curr, idx, j):
                    used_cols[j] = True
                    curr[idx][j] = "Q"
                    dfs(curr, idx + 1)
                    curr[idx][j] = "."
                    used_cols[j] = False
        dfs(board, 0)
        return ans