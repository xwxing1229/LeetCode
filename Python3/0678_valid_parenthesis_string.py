# https://leetcode.cn/problems/valid-parenthesis-string/

class Solution:
    def checkValidString(self, s: str) -> bool:
        # mx: maximum number of unmatched "(".
        # mn: minimum number of unmatched "(".
        mx, mn = 0, 0
        for ch in s:
            if ch == "(":
                mx += 1
                mn += 1
            elif ch == ")":
                mx -= 1
                mn -= 1
                if mx < 0:
                    return False
            else:
                mx += 1
                mn -= 1
            mn = max(mn, 0)
        return mn == 0