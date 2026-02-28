# https://leetcode.cn/problems/concatenation-of-consecutive-binary-numbers/

class Solution:
    def concatenatedBinary(self, n: int) -> int:
        mod = int(1e9) + 7
        res = 0
        shift = 0
        for num in range(1, n+1):
            # num = 2 ^ k
            if (num & (num-1)) == 0:
                shift += 1
            res = ((res << shift) + num) % mod
        return res