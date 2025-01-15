# https://leetcode.cn/problems/sum-of-digit-differences-of-all-pairs/

class Solution:
    def sumDigitDifferences(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        num_len = len(str(nums[0]))
        digits = [[0 for _ in range(10)] for _ in range(num_len)]
        for num in nums:
            i, val = 0, num
            while val > 0:
                digits[i][val % 10] += 1
                i += 1
                val //= 10
        res = 0
        for cnts in digits:
            for i in range(10):
                for j in range(i+1, 10):
                    res += cnts[i] * cnts[j]
        return res