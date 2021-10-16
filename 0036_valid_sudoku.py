# https://leetcode-cn.com/problems/valid-sudoku/
class Solution:
    def isValidSudoku(self, board):
        """
        Inputs:
            board: list[list[int]]
        Outputs:
            res: bool
        """

        row, col, block = defaultdict(set), defaultdict(set), defaultdict(set)
        for i in range(9):
            for j in range(9):
                k = i // 3 * 3 + j // 3
                val = board[i][j]

                if val == '.':
                    continue

                if val in row[i] or val in col[j] or val in block[k]:
                    return False

                row[i].add(val)
                col[j].add(val)
                block[k].add(val)

        return True