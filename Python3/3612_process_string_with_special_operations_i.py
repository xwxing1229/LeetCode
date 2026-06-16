# https://leetcode.cn/problems/process-string-with-special-operations-i/

class Solution:
    def processStr(self, s: str) -> str:
        res = []
        for ch in s:
            if ch == "*":
                if res:
                    res.pop()
            elif ch == "#":
                res += res
            elif ch == "%":
                res.reverse()
            else:
                res.append(ch)
        return "".join(res)