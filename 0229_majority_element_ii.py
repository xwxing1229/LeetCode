# https://leetcode-cn.com/problems/majority-element-ii/

class Solution:
    def majorityElement(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """

        # Boyer–Moore majority vote algorithm.

        # There are at most 2 elements that meet the requirement.
        tmp1 = 0
        tmp2 = 0
        count1 = 0
        count2 = 0

        for i in nums:
            if i == tmp1:
                count1 = count1 + 1
            elif i == tmp2:
                count2 = count2 + 1
            elif count1 == 0:
                tmp1 = i
                count1 = 1
            elif count2 == 0:
                tmp2 = i
                count2 = 1
            else:
                count1 = count1 - 1
                count2 = count2 - 1

        # Check how many tmp1 and tmp2 are there in nums.
        count1 = 0
        count2 = 0
        for i in nums:
            if i == tmp1:
                count1 = count1 + 1
            if i == tmp2:
                count2 = count2 + 1

        res = []
        n = len(nums)
        if count1 > n // 3:
            res.append(tmp1)
        if count2 > n // 3:
            res.append(tmp2)
        return res