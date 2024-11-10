# https://leetcode.cn/problems/design-neighbor-sum-service/

class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        n = len(grid)
        self.adjacent_sum = [0 for _ in range(n*n)]
        self.diagonal_sum = [0 for _ in range(n*n)]
        adj_dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        diag_dirs = [[-1, -1], [-1, 1], [1, -1], [1, 1]]
        for i in range(n):
            for j in range(n):
                adj_sum, diag_sum = 0, 0
                for d in adj_dirs:
                    i0, j0 = i+d[0], j+d[1]
                    if i0 < 0 or i0 >= n or j0 < 0 or j0 >= n:
                        continue
                    adj_sum += grid[i0][j0]
                for d in diag_dirs:
                    i0, j0 = i+d[0], j+d[1]
                    if i0 < 0 or i0 >= n or j0 < 0 or j0 >= n:
                        continue
                    diag_sum += grid[i0][j0]
                self.adjacent_sum[grid[i][j]] = adj_sum
                self.diagonal_sum[grid[i][j]] = diag_sum                

    def adjacentSum(self, value: int) -> int:
        return self.adjacent_sum[value]

    def diagonalSum(self, value: int) -> int:
        return self.diagonal_sum[value]


# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)