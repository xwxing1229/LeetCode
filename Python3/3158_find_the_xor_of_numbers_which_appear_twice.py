# https://leetcode.cn/problems/find-the-xor-of-numbers-which-appear-twice/

class Solution:
    def duplicateNumbersXOR(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        s = set()
        res = 0
        for num in nums:
            if num not in s:
                s.add(num)
            else:
                res ^= num
        return res