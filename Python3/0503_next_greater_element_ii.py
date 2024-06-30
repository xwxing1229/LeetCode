# https://leetcode.cn/problems/next-greater-element-ii/

class Solution:
    def nextGreaterElements(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        n = len(nums)
        res = [-1 for _ in range(n)]
        stack = []
        nums += nums[:-1]
        for i, num in enumerate(nums):
            while stack and stack[-1][0] < num:
                val, idx = stack.pop()
                res[idx % n] = num
            stack.append((num, i))
        return res