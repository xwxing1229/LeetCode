# https://leetcode.cn/problems/first-missing-positive/

class Solution:
    def firstMissingPositive(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        for i in range(n):
            num = nums[i]
            while (num >= 1) and (num <= n):
                tmp = nums[num-1]
                # If the (num-1)th number is already num, break.
                if tmp == num:
                    break
                    
                # Swap nums[num-1] and nums[i].
                nums[num-1] = num
                nums[i] = tmp
                num = tmp

        for i, num in enumerate(nums):
            if i != num - 1:
                return i+1
        return n+1