# https://leetcode.cn/problems/game-of-life/

class Solution:
    def gameOfLife(self, board):
        """
        Do not return anything, modify board in-place instead.
        """

        """
        Inputs:
            board: list[list[int]]
        Outputs:
            None
        """
        rows = len(board)
        cols = len(board[0])
        for row in range(rows):
            for col in range(cols):
                # Check one cell.
                cnt = 0
                for i in range(-1, 2):
                    r = row + i
                    for j in range(-1, 2):
                        c = col + j
                        if (r < 0) or (r >= rows) or (c < 0) or (c >= cols):
                            continue
                        if (r == row) and (c == col):
                            continue
                        if (board[r][c] == 1) or (board[r][c] == 3):
                            cnt = cnt + 1
                # 2: 0 -> 1
                # 3: 1 -> 0
                if board[row][col] == 1:
                    if cnt < 2 or cnt > 3:
                        board[row][col] = 3
                else:
                    if cnt == 3:
                        board[row][col] = 2

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == 2:
                    board[row][col] = 1
                elif board[row][col] == 3:
                    board[row][col] = 0