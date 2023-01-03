# https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/

class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """
        pre, cur = 100, 0
        s += " "
        for i, ch in enumerate(s):
            if ch.isdigit():
                cur = cur * 10 + int(ch)
            elif ch == " " and s[i-1].isdigit():
                if pre == 100 or pre < cur:
                    pre = cur
                    cur = 0
                else:
                    return False
        return True