# https://leetcode.cn/problems/check-if-all-1s-are-at-least-length-k-places-away/

class Solution:
    def kLengthApart(self, nums, k):
        """
        Inputs:
            nums: list[int]
            k: int
        Outputs:
            res: bool
        """
        pre = -k - 1
        for i, num in enumerate(nums):
            if num == 1:
                if i - pre - 1 < k:
                    return False
                pre = i
        return True