# https://leetcode.cn/problems/find-the-pivot-integer/

class Solution:
    def pivotInteger(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        target = (n+1) * n / 2
        tmp = int(sqrt(target))
        return tmp if tmp*tmp == target else -1