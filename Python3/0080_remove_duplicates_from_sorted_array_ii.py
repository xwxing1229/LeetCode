# https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

class Solution:
    def removeDuplicates(self, nums):
        """
        Inputs:
            n: list[int]
        Outputs:
            res: int
        """

        slow, n = 2, len(nums)
        if n <= 2:
            return n
        for fast in range(2, n):
            if nums[fast] != nums[slow-2]:
                nums[slow] = nums[fast]
                slow += 1
        return slow