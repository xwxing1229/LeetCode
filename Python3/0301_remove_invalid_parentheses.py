# https://leetcode.cn/problems/remove-invalid-parentheses/

class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        def isValid(s: str) -> bool:
            cnt = 0
            for ch in s:
                if ch == "(":
                    cnt += 1
                elif ch == ")":
                    cnt -= 1
                    if cnt < 0:
                        return False
            return cnt == 0

        prev = set()
        prev.add(s)
        while True:
            res = [t for t in prev if isValid(t)]
            if res:
                return res
            curr = set()
            for t in prev:
                for i, ch in enumerate(t):
                    if ch == "(" or ch == ")":
                        curr.add(t[:i] + t[i+1:])
            prev = curr