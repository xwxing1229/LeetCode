# https://leetcode.cn/problems/sum-of-subsequence-widths/

class Solution:
    def sumSubseqWidths(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        nums.sort()
        end_at_i, pow2 = 0, 2
        res = 0
        for i in range(1, len(nums)):
            end_at_i = ((nums[i] - nums[i-1]) * (pow2 - 1) + 2 * end_at_i) % 1000000007
            pow2 = pow2 * 2 % 1000000007;
            res = (res + end_at_i) % 1000000007
        return res