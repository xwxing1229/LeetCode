# https://leetcode.cn/problems/available-captures-for-rook/

class Solution:
    def numRookCaptures(self, board):
        """
        Inputs:
            board: list[list[str]]
        Outputs:
            res: int
        """        
        res = 0
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        for i in range(8):
            for j in range(8):
                if board[i][j] != "R":
                    continue
                for d in dirs:
                    i0, j0 = i+d[0], j+d[1]
                    while i0 >= 0 and i0 < 8 and j0 >= 0 and j0 < 8:
                        if board[i0][j0] == "p":
                            res += 1
                            break
                        elif board[i0][j0] == "B":
                            break
                        
                        i0 += d[0]
                        j0 += d[1]
        return res