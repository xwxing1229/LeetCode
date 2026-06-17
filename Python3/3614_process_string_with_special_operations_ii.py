# https://leetcode.cn/problems/process-string-with-special-operations-ii/

class Solution:
    def processStr(self, s: str, k: int) -> str:
        # "*": remove the last ch from the current string
        # "# ": duplicate the current string and append it to itself
        # "%": reverse the current string
        # ch : append it to the current string
        
        size = [0 for _ in range(len(s))]
        curr = 0
        for i, ch in enumerate(s):
            if ch == "*":
                curr = max(curr - 1, 0)
            elif ch == "#":
                curr *= 2
            elif ch != "%":
                curr += 1
            size[i] = curr
        
        if k >= size[-1]:
            return "."
        
        for i in range(len(s)-1, -1, -1):
            ch = s[i]
            curr = size[i]
            if ch == "#":
                if k >= curr // 2:
                    k -= curr // 2
            elif ch == "%":
                k = curr - 1 - k
            elif ch != "*" and k == curr - 1:
                return ch
        return "."