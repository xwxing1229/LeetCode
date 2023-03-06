# https://leetcode.cn/problems/predict-the-winner/

"""
Check solution for a DP-based method.
"""

# class Solution:
#     def PredictTheWinner(self, nums):
#         """
#         Inputs:
#             nums: list[int]
#         Outputs:
#             res: bool
#         """
#         self.nums = nums
#         if self.dfs(0, len(nums)-1, 0, 0) >= 0:
#             return True
#         else:
#             return False

#     def dfs(self, left, right, total1, total2):
#         if left + 1 >= right:
#             total1 += max(self.nums[left], self.nums[right])
#             total2 += min(self.nums[left], self.nums[right])
#             return total1 - total2
        
#         diff1 = -self.dfs(left+1, right, total2, total1 + self.nums[left])
#         diff2 = -self.dfs(left, right-1, total2, total1 + self.nums[right])
#         return max(diff1, diff2)


# This is an improved version based on the idea above with repeated operations avoided.
class Solution:
    def PredictTheWinner(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        self.nums = nums
        self.n = len(nums)
        self.records = dict()
        if self.dfs(0, self.n-1) >= 0:
            return True
        else:
            return False

    def dfs(self, left, right):
        key = left * self.n + right
        if key in self.records:
            return self.records[key]
        if left + 1 >= right:
            diff = abs(self.nums[left] - self.nums[right])
            self.records[key] = diff
            return diff
        
        diff1 = self.nums[left] - self.dfs(left+1, right)
        diff2 = self.nums[right] - self.dfs(left, right-1)
        diff = max(diff1, diff2)
        self.records[key] = diff
        return diff
