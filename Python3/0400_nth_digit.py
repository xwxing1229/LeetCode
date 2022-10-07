# https://leetcode.cn/problems/nth-digit/

class Solution:
    def findNthDigit(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        idx, num = 0, 0
        length, scale = 1, 1
        while idx + length * 9 * scale <= n:
            idx = idx + length * 9 * scale
            num = num + 9 * scale
            length = length + 1
            scale = scale * 10

        val = num + (n - idx) // length
        rem = (n - idx) % length
        if rem != 0:
            val = val + 1
            for i in range(length-rem):
                val = val // 10
        res = val % 10
        return res