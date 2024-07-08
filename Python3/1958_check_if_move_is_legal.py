# https://leetcode.cn/problems/check-if-move-is-legal/

class Solution:
    def checkMove(self, board, rMove, cMove, color):
        """
        Inputs:
            board: list[list[int]]
            rMove, cMove: int
            color: str
        Outputs:
            res: bool
        """
        m, n = len(board), len(board[0])
        dirs = [[-1,-1], [-1,0], [-1,1], [0,-1], [0,1], [1,-1], [1,0], [1,1]]
        for d in dirs:
            i, j = rMove+d[0], cMove+d[1]
            length = 1
            valid = False
            while i >= 0 and i < m and j >= 0 and j < n:
                length += 1
                if board[i][j] == color:
                    valid = True
                    break
                elif board[i][j] == ".":
                    break
                i += d[0]
                j += d[1]
            if valid and length >= 3:
                return True
        return False