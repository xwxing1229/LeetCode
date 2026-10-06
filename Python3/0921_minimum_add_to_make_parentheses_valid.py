# https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        res = 0
        cnt = 0
        for ch in s:
            if ch == "(":
                cnt += 1
            else:
                cnt -= 1
                if cnt < 0:
                    res -= cnt
                    cnt = 0
        return res + cnt