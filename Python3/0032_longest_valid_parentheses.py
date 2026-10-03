# https://leetcode.cn/problems/longest-valid-parentheses/

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res = 0
        stk = [-1]
        for i, ch in enumerate(s):
            if ch == "(":
                stk.append(i)
            elif len(stk) > 1:
                stk.pop()
                res = max(res, i-stk[-1])
            else:
                stk[0] = i
        return res