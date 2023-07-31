# https://leetcode.cn/problems/jewels-and-stones/

class Solution:
    def numJewelsInStones(self, jewels, stones):
        """
        Inputs:
            jewels, stones: str
        Outputs:
            res: int
        """
        s = set()
        for ch in jewels:
            s.add(ch)
        res = 0
        for ch in stones:
            if ch in s:
                res += 1
        return res