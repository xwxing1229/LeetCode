# https://leetcode-cn.com/problems/largest-perimeter-triangle/
class Solution:
    def largestPerimeter(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        nums.sort()
        res = 0
        
        i = len(nums) - 1
        j = i - 1
        k = j - 1
        while k >= 0:
            l1, l2, l3 = nums[i], nums[j], nums[k]
            if l1 < l2 + l3:
                res = l1 + l2 + l3
                break
            else:
                i = i - 1
                j = j - 1
                k = k - 1
        return res