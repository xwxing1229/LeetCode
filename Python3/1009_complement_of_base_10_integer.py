# https://leetcode.cn/problems/complement-of-base-10-integer/

class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if n == 0:
            return 1
        res = 0
        move = 0
        while n > 0:
            val = 1 - (n & 1)
            res = (val << move) + res
            n >>= 1
            move += 1
        return res