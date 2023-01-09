# https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution:
    def reinitializePermutation(self, n: int) -> int:
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        res = 0
        start, cur, half = 1, 1, n//2
        while True:
            if cur < half:
                cur *= 2
            else:
                cur = cur * 2 + 1 - n
            res += 1

            if start == cur:
                break
        return res