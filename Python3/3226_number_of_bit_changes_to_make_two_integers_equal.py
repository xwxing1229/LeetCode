# https://leetcode.cn/problems/number-of-bit-changes-to-make-two-integers-equal/

class Solution:
    def minChanges(self, n: int, k: int) -> int:
        res = 0
        while n != k:
            if (n&1) != (k&1):
                if (n&1) == 1:
                    res += 1
                else:
                    return -1
            n >>= 1
            k >>= 1
        return res