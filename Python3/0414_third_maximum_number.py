# https://leetcode.cn/problems/third-maximum-number/

class Solution:
    def thirdMax(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        s = set(nums)
        max_1, max_2, max_3 = float("-inf"), float("-inf"), float("-inf")
        for i in s:
            if i > max_1:
                max_3 = max_2
                max_2 = max_1
                max_1 = i
            elif i > max_2:
                max_3 = max_2
                max_2 = i
            elif i > max_3:
                max_3 = i
        if len(s) < 3:
            return max_1
        else:
            return max_3

        """
        nums_new = list(set(nums))
        n = len(nums_new)
        if n < 3:
            return max(nums_new)

        nums_new.sort()
        nums_new.pop()
        nums_new.pop()
        return nums_new[n-3]
        """