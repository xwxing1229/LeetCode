# https://leetcode.cn/problems/predict-the-winner/

"""
Check solution for a DP-based method which is time-efficient.
"""

class Solution:
    def PredictTheWinner(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        self.nums = nums
        if self.dfs(0, len(nums)-1, 0, 0) >= 0:
            return True
        else:
            return False

    def dfs(self, left, right, total1, total2):
        if left + 1 >= right:
            total1 += max(self.nums[left], self.nums[right])
            total2 += min(self.nums[left], self.nums[right])
            return total1 - total2
        
        diff1 = -self.dfs(left+1, right, total2, total1 + self.nums[left])
        diff2 = -self.dfs(left, right-1, total2, total1 + self.nums[right])
        return max(diff1, diff2)