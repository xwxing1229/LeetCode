# https://leetcode-cn.com/problems/largest-number/

class Solution:
    def largestNumber(self, nums):
        """
        Inputs:
            nums: list[int]
        Outpus:
            res: str
        """

        n = len(nums)

        # Sort.
        # If 'ab' < 'ba', then b should be in front of a.
        for i in range(n-1):
            for j in range(i+1, n):
                if str(nums[i]) + str(nums[j]) < str(nums[j]) + str(nums[i]):
                    nums[i], nums[j] = nums[j], nums[i]

        res = ''.join([str(i) for i in nums])

        # Check if the final result is '0'.
        if int(res) == 0:
            res = '0'

        return res