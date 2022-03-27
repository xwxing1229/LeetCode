# https://leetcode-cn.com/problems/minimum-size-subarray-sum/

class Solution:
    def minSubArrayLen(self, s, nums):
        """
        Inputs:
            s: int
            nums: list[int]
        Outputs:
            res: int
        """
        
        # Left and right pointers.
        left = 0
        right = 0
        total = 0 # sum of elements in the subarray
        
        n = len(nums)
        res = n + 1
        while right < n:
            total = total + nums[right] # add an element
            right = right + 1
            while total >= s:
                res = min(res, right-left)
                # Remove the leftmost element.
                total = total - nums[left]
                left = left + 1
        
        if res == n + 1:
            res = 0
        return res