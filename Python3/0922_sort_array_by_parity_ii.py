# https://leetcode.cn/problems/sort-array-by-parity-ii/

class Solution:
    def sortArrayByParityII(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        res = [0 for _ in range(len(nums))]
        even, odd = 0, 1
        for num in nums:
            if num % 2 == 0:
                res[even] = num
                even += 2
            else:
                res[odd] = num
                odd += 2
        return res