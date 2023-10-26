# https://leetcode.cn/problems/count-the-digits-that-divide-a-number/

class Solution:
    def countDigits(self, num: int) -> int:
        """
        Inputs:
            num: int
        Outputs:
            res: int
        """
        res, val = 0, num
        while val > 0:
            if num % (val % 10) == 0:
                res += 1
            val //= 10
        return res