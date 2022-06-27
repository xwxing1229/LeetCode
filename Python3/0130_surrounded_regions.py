# https://leetcode.cn/problems/surrounded-regions/

class Solution:
    def solve(self, board):
        """
        Do not return anything, modify board in-place instead.
        """

        """
        Inputs:
            board: list[list[str]]
        """
        
        rows = len(board)
        cols = len(board[0])

        for col in range(cols):
            self.backtrack(board, rows, cols, 0, col)
            self.backtrack(board, rows, cols, rows-1, col)
        for row in range(1, rows-1):
            self.backtrack(board, rows, cols, row, 0)
            self.backtrack(board, rows, cols, row, cols-1)

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == "A":
                    board[row][col] = "O"
                elif board[row][col] == "O":
                    board[row][col] = "X"

    def backtrack(self, board, rows, cols, row, col):
        if (row < 0) or (row >= rows) or (col < 0) or (col >= cols) or (board[row][col] != "O"):
            return

        board[row][col] = "A"

        self.backtrack(board, rows, cols, row+1, col)
        self.backtrack(board, rows, cols, row-1, col)
        self.backtrack(board, rows, cols, row, col+1)
        self.backtrack(board, rows, cols, row, col-1)