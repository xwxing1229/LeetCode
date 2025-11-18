# https://leetcode.cn/problems/1-bit-and-2-bit-characters/

class Solution:
    def isOneBitCharacter(self, bits):
        """
        Inputs:
        bits: list[int]
        Outputs:
        res: bool
        """
        n, i = len(bits), 0
        while i < n-1:
            i += bits[i] + 1
        return i == n-1