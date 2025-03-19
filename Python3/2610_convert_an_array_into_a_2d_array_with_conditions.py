# https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/

class Solution:
    def findMatrix(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: list[list[int]]
        """
        nums.sort()
        res = [[nums[0]]]
        idx = 0
        for i in range(1, len(nums)):
            num = nums[i]
            if num == nums[i-1]:
                idx += 1
                if idx == len(res):
                    res.append([num])
                else:
                    res[idx].append(num)
            else:
                idx = 0
                res[idx].append(num)
        return res