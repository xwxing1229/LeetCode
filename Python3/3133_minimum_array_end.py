# https://leetcode.cn/problems/minimum-array-end/

class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        i, j = 0, 0
        while (n >> j):
            # The value at the ith position of x is 0.
            if ((x >> i) & 1) == 0:
                # Put the value at the jth position of n-1 here.
                x |= ((n >> j) & 1) << i
                j += 1
            i += 1
        return x