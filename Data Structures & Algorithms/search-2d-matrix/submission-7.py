class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])

        l, r = 0, ROWS * COLS - 1

        while l <= r:
            m = (l + r) // 2
            m_val = matrix[m // COLS][m % COLS]

            if m_val == target:
                return True
            elif m_val < target:
                l = m + 1
            else:
                r = m - 1

        return False