# https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

class Solution:
    def maximumSum(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        res = -1
        record = dict()
        for num in nums:
            digitsum, tmp = 0, num
            while tmp > 0:
                digitsum += tmp % 10
                tmp //= 10
            if digitsum in record:
                res = max(res, num + record[digitsum])
                record[digitsum] = max(record[digitsum], num)
            else:
                record[digitsum] = num
        return res