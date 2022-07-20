# https://leetcode.cn/problems/summary-ranges/

class Solution:
    def summaryRanges(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[str]
        """
        n = len(nums)
        res = []
        if n == 0:
            return res

        left = nums[0]
        nums.append(0)
        for i in range(1, n+1):
            pre = nums[i-1]
            if nums[i] - pre > 1 or i == n:
                if left < pre:
                    tmp = str(left) + "->" + str(pre)
                else:
                    tmp = str(left)
                res.append(tmp)
                left = nums[i]
        return res