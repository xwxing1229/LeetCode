# https://leetcode.cn/problems/smallest-string-with-a-given-numeric-value/

class Solution:
    def getSmallestString(self, n, k):
        """
        Inputs:
            n, k: int
        Outputs:
            res: str
        """
        res = ""
        cur = n
        for i in range(n):
            diff = k - cur
            if diff > 25:
                res += "z"
                cur += 25
            else:
                res = "a" * (n-i-1) + chr(ord("a") + diff) + res
                break
        return res