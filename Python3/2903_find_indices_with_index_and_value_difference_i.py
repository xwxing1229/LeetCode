# https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/

class Solution:
    def findIndices(self, nums, indexDifference, valueDifference):
        """
        Inputs:
            nums: list[int]
            indexDifference, valueDifference: int
        Outputs:
            res: list[int]
        """
        num_min, index_min = nums[0], 0
        num_max, index_max = nums[0], 0
        res = [-1, -1]
        for j in range(indexDifference, len(nums)):
            i = j-indexDifference
            if nums[i] < num_min:
                num_min = nums[i]
                index_min = i
            if nums[i] > num_max:
                num_max = nums[i]
                index_max = i

            if nums[j] - num_min >= valueDifference:
                return [index_min, j]
            elif num_max - nums[j] >= valueDifference:
                return [index_max, j]
        return res