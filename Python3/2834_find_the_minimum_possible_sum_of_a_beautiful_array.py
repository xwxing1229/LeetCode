# https://leetcode.cn/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

class Solution:
    def minimumPossibleSum(self, n: int, target: int) -> int:
        mod = int(1e9) + 7
        half = target // 2
        if n <= half:
            res = ((1 + n) * n // 2) % mod
        else:
            res = ((1 + half) * half // 2) % mod
            remain = n - half
            res = (res + (target + target + remain - 1) * remain // 2) % mod
        return res