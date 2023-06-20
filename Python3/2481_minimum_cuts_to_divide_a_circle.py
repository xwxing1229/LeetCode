# https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/

class Solution:
    def numberOfCuts(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        if n == 1:
            return 0
        return n//2 if n % 2 == 0 else n