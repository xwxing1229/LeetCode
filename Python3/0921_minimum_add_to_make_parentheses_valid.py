# https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/

class Solution:
    def minAddToMakeValid(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        cnt_open, cnt_close = 0, 0
        for ch in s:
            if ch == "(":
                cnt_open += 1
            else:
                if cnt_open > 0:
                    cnt_open -= 1
                else:
                    cnt_close += 1

        res = cnt_open + cnt_close
        return res