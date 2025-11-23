# https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/

class Solution:
    def minimumOperations(self, nums: list[int]) -> int:
        res = 0
        for num in nums:
            rem = num % 3
            res += min(rem, 3-rem)
        return res