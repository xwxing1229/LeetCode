# https://leetcode.cn/problems/max-consecutive-ones/

class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res, cnt = 0, 0
        for num in nums:
            if num == 1:
                cnt += 1
            else:
                res = max(res, cnt)
                cnt = 0
        res = max(res, cnt)
        return res