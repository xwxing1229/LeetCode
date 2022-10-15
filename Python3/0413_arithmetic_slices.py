# https://leetcode.cn/problems/arithmetic-slices/

class Solution:
    def numberOfArithmeticSlices(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res, n = 0, len(nums)
        if n < 3:
            return res
        
        start = 0
        diff = nums[1] - nums[0]
        for cur in range(2, n):
            if nums[cur] - nums[cur-1] != diff:
                length = cur - start
                res = res + self.numberOfSub(length)

                start = cur - 1
                diff = nums[cur] - nums[start]

        if nums[n-1] - nums[n-2] == diff:
            res = res + self.numberOfSub(n-start)

        return res

    def numberOfSub(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        # Compute 1 + 2 + ... + (n-2).
        res = (n-2) * (n-1) // 2
        return res
