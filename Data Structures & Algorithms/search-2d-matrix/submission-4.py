class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l, r = 0, len(matrix) - 1
        m = (r + l + 1) // 2
        
        while l < r:
            print(l, r)
            if target < matrix[m][0]:
                r = m - 1
            else:
                l = m
            m = (r + l + 1) // 2
        print(l, r)

        row = matrix[m]

        l, r = 0, len(row) - 1
        m = (r + l + 1) // 2

        while l < r:
            print(l, r)
            if target < row[m]:
                r = m - 1
            else:
                l = m
            m = (r + l + 1) // 2

        return target == row[m]