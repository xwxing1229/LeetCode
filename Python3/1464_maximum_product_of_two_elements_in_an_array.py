# https://leetcode.cn/problems/maximum-product-of-two-elements-in-an-array/

class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        mx1 = max(nums[0], nums[1])
        mx2 = nums[0] + nums[1] - mx1
        for i in range(2, len(nums)):
            num = nums[i]
            if num >= mx1:
                mx2 = mx1
                mx1 = num
            elif num > mx2:
                mx2 = num
        return (mx1 - 1) * (mx2 - 1)