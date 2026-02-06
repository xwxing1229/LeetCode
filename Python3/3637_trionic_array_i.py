# https://leetcode.cn/problems/trionic-array-i/

class Solution:
    def isTrionic(self, nums: list[int]) -> bool:
        n = len(nums)
        p, q = 0, 0
        for i in range(1, n):
            if nums[i] > nums[i-1]:
                p = i
            else:
                break
        for i in range(p+1, n):
            if nums[i] < nums[i-1]:
                q = i
            else:
                break
        for i in range(q+1, n):
            if nums[i] <= nums[i-1]:
                return False
        return 0 < p and p < q and q < n-1