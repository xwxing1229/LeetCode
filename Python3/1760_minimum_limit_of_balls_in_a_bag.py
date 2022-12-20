# https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/

class Solution:
    def minimumSize(self, nums, maxOperations):
        """
        Inputs:
            nums: list[int]
            maxOperations: int
        Outputs:
            res: int
        """
        left, right = 1, max(nums)
        res = right
        while left <= right:
            mid = left + (right - left) // 2
            requiredOps = 0
            for i in nums:
                requiredOps += ((i - 1) // mid)
            if requiredOps <= maxOperations:
                right = mid - 1
                res = mid
            else:
                left = mid + 1
        return res