# https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/

class Solution:
    def punishmentNumber(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        res = 0
        for i in range(1, n+1):
            sq = i * i
            if self.dfs(str(sq), i, -1, 0):
                res += sq
        return res

    def dfs(self, s, num, idx, cur):
        if cur > num:
            return False
        elif idx == len(s)-1 and num == cur:
            return True
        for i in range(idx+1, len(s)):
            if self.dfs(s, num, i, cur+int(s[idx+1: i+1])):
                return True
        return False