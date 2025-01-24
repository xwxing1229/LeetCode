# https://leetcode.cn/problems/find-the-distinct-difference-array/

class Solution:
    def distinctDifferenceArray(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[int]
        """
        s = set()
        n = len(nums)
        left, right = [0 for _ in range(n+1)], [0 for _ in range(n+1)]
        for i in range(n):
            if nums[i] not in s:
                left[i+1] = left[i] + 1
                s.add(nums[i])
            else:
                left[i+1] = left[i]

        s.clear()
        for i in range(n-1, -1, -1):
            if nums[i] not in s:
                right[i] = right[i+1] + 1
                s.add(nums[i])
            else:
                right[i] = right[i+1]

        res = [0 for _ in range(n)]
        for i in range(n):
            res[i] = left[i+1] - right[i+1]
        return res