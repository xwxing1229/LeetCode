# https://leetcode-cn.com/problems/contains-duplicate/

class Solution:
    def containsDuplicate(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """

        count = {}
        for i in nums:
            count[i] = count.get(i,0) + 1
            if count[i] > 1:
                return True
        return False