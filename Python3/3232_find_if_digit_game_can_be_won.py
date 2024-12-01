# https://leetcode.cn/problems/find-if-digit-game-can-be-won/

class Solution:
    def canAliceWin(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        s1, s2 = 0, 0
        for num in nums:
            if num < 10:
                s1 += num
            else:
                s2 += num
        return s1 != s2