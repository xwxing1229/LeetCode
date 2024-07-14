# https://leetcode.cn/problems/find-if-array-can-be-sorted/

class Solution:
    def canSortArray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        pre_group_max = 0
        cur_group_max = 0
        cur_group_1cnt = 0
        for num in nums:
            if num.bit_count() == cur_group_1cnt:
                cur_group_max = max(cur_group_max, num)
            else:
                pre_group_max = cur_group_max
                cur_group_max = num
                cur_group_1cnt = num.bit_count()
            if num < pre_group_max:
                return False
        return True