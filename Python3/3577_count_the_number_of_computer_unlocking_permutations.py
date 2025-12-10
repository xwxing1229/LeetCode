# https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/

class Solution:
    def countPermutations(self, complexity: list[int]) -> int:
        res = 1
        mod = 10**9+7
        for i in range(1, len(complexity)):
            if complexity[i] <= complexity[0]:
                return 0
            res = res * i % mod
        return res