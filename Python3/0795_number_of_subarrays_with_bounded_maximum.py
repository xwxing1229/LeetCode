# https://leetcode.cn/problems/number-of-subarrays-with-bounded-maximum/

class Solution:
    def numSubarrayBoundedMax(self, nums, left, right):
        """
        Inputs:
            nums: list[int]
            left: int
            right: int
        Outputs:
            res: int
        """
        res = 0
        # The index of the start element of the subarray,
        # and the index of the neatest element which is >= left.
        start, nearest = 0, 0
        cur_max = nums[0]
        for i, num in enumerate(nums):
            if num > cur_max:
                cur_max = num

            if num >= left:
                nearest = i
                
            if cur_max >= left and cur_max <= right:
                res += nearest - start + 1
            elif cur_max > right:
                start = i + 1
                if start < len(nums):
                    cur_max = nums[start]
        return res
