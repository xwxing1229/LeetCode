# https://leetcode.cn/problems/largest-combination-with-bitwise-and-greater-than-zero/

class Solution:
    def largestCombination(self, candidates):
        """
        Inputs:
            candidates: list[int]
        Outputs:
            res: int
        """

        cnts = [0 for _ in range(24)]
        for i in range(len(candidates)):
            num = candidates[i]
            k = 0
            while num > 0:
                cnts[k] += (num & 1)
                num >>= 1
                k += 1
        return max(cnts)