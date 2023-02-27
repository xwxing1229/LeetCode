# https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/

class Solution:
    def movesToMakeZigzag(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """
        return min(self.zigzag(nums[:], 0), self.zigzag(nums[:], 1))

    def zigzag(self, nums, start):
        res, n = 0, len(nums)
        for i in range(start, n, 2):
            if i - 1 >= 0 and nums[i] >= nums[i-1]:
                res += (nums[i] - nums[i-1] + 1)
                nums[i] = nums[i-1] - 1
            if i + 1 < n and nums[i] >= nums[i+1]:
                res += (nums[i] - nums[i+1] + 1)
                nums[i] = nums[i+1] - 1
        return res