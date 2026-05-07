# https://leetcode.cn/problems/jump-game-ix/

class Solution:
    def maxValue(self, nums: list[int]) -> list[int]:
        n = len(nums)
        premax = [num for num in nums]
        for i in range(1, n):
            premax[i] = max(premax[i-1], nums[i])
        
        sufmin = nums[-1]
        sufmin_idx = n - 1

        res = [premax[-1] for i in range(n)]
        for i in range(n-2, -1, -1):
            if premax[i] <= sufmin:
                res[i] = premax[i]
            else:
                res[i] = res[sufmin_idx]
            
            if nums[i] < sufmin:
                sufmin = nums[i]
                sufmin_idx = i
        return res