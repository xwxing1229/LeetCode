# https://leetcode.cn/problems/remove-outermost-parentheses/

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = ""
        cnt, left = 0, 0
        for i, ch in enumerate(s):
            if ch == "(":
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    res += s[left+1: i]
                    left = i + 1
        return res