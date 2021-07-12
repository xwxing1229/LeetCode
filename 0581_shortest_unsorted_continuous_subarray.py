# https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
class Solution:
    def findUnsortedSubarray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        if n == 1:
            return 0

        # If there is a number which is smaller than the current number and
        # is on the right-hand side of the current number, than the current
        # number should be in the subarray.
        # If there is a number which is larger than the current number and
        # is on the left-hand side of the current number, than the current
        # number should be in the subarray.

        rightmin = nums[n-1]
        l = n - 1
        for i in range(n-1, -1, -1):
            if nums[i] > rightmin:
                l = i
            else:
                rightmin = nums[i]

        leftmax = nums[0]
        r = 0
        for i in range(n):
            if nums[i] < leftmax:
                r = i
            else:
                leftmax = nums[i]

        return max(0, r-l+1)