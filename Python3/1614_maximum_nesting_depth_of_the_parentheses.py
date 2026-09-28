# https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/

class Solution:
    def maxDepth(self, s: str) -> int:
        res = 0
        cnt = 0
        for ch in s:
            cnt += (ch == "(") - (ch == ")")
            res = max(res, cnt)
        return res