# https://leetcode.cn/problems/alphabet-board-path/
class Solution:
    def alphabetBoardPath(self, target):
        """
        Inputs:
            target: str
        Outputs:
            res: str
        """
        res = ""
        pre = "a"
        pre_row, pre_col = 0, 0
        for ch in target:
            ch_row, ch_col = (ord(ch) - ord("a")) // 5, (ord(ch) - ord("a")) % 5
            drow, dcol = ch_row - pre_row, ch_col - pre_col
            if drow > 0:
                res_row = "D" * drow
            else:
                res_row = "U" * (-drow)
            if dcol > 0:
                res_col = "R" * dcol
            else:
                res_col = "L" * (-dcol)
            
            if ch == "z" and pre != "z":
                res += (res_row[:-1] + res_col + "D!")
            else:
                res += (res_row + res_col + "!")
            
            pre = ch
            pre_row, pre_col = ch_row, ch_col
        return res