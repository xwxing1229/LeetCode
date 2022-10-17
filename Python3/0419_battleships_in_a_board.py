# https://leetcode.cn/problems/battleships-in-a-board/

class Solution:
    def countBattleships(self, board):
        """
        Inputs:
            board: list[list[str]]
        Outputs:
            res: int
        """
        res = 0
        rows, cols = len(board), len(board[0])
        if board[0][0] == "X":
            res = 1
        # Just check the upper and left sides.
        for row in range(1, rows):
            if board[row][0] == "X" and board[row-1][0] == ".":
                res = res + 1
        for col in range(1, cols):
            if board[0][col] == "X" and board[0][col-1] == ".":
                res = res + 1
        for row in range(1, rows):
            for col in range(1, cols):
                if board[row][col] == "X":
                    if board[row-1][col] == "." and board[row][col-1] == ".":
                        res = res + 1
        return res