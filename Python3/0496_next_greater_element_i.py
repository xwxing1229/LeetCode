# https://leetcode.cn/problems/next-greater-element-i/

class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        Inputs:
            nums1: list[int]
            nums2: list[int]
        Outputs:
            res: list[int]
        """
        table = dict()
        stack = [] # monotone stack
        for i in range(len(nums2)-1, -1, -1):
            num = nums2[i]
            while stack and stack[-1] <= num:
                stack.pop()
            if stack:
                table[num] = stack[-1]
            else:
                table[num] = -1
            stack.append(num)
        res = []
        for num in nums1:
            res.append(table[num])
        return res