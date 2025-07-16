# https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/

class Solution:
    def maximumLength(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        def f(rem):
            res = 0
            for num in nums:
                res += (num % 2 == rem)
            return res
        
        res = 1
        pre = nums[0] % 2
        for num in nums:
            cur = num % 2
            if cur != pre:
                res += 1
                pre = cur
        res = max(res, f(0), f(1))
        return res