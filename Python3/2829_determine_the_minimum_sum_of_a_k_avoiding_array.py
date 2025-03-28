# https://leetcode.cn/problems/determine-the-minimum-sum-of-a-k-avoiding-array/

class Solution:
    def minimumSum(self, n: int, k: int) -> int:
        half = k // 2
        if n <= half:
            return (1 + n) * n // 2
        res = (1 + half) * half // 2
        res += (k + k + n - half - 1) * (n - half) // 2
        return res