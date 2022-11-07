# https://leetcode.cn/problems/132-pattern/

class Solution:
    def find132pattern(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """

        n = len(nums)
        # leftMin[j]: the minimum number in nums[0], nums[1], ..., nums[j-1]
        leftMin = [nums[0] for j in range(n)]
        for j in range(2, n):
            if nums[j-1] < leftMin[j-1]:
                leftMin[j] = nums[j-1]
            else:
                leftMin[j] = leftMin[j-1]

        stk = [nums[n-1]] # monotonic stack
        for j in range(n-2, 0, -1):
            J = nums[j]
            maxLessThanJ = -1000000000
            while stk and stk[-1] < J:
                maxLessThanJ = stk.pop()

            if maxLessThanJ > leftMin[j]:
                return True

            stk.append(J)

        return False