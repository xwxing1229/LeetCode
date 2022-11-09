# https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/

class Solution:
    def minMoves2(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Let n = len(nums) and sort nums.
        # If n % 2 == 0, the final element should be any integer in the range
        # [nums[n//2-1], nums[n//2]].
        # If n % 2 == 1, the final element should be nums[n//2].
        n = len(score)
        nums.sort()
        idx = (n+1) // 2
        res = sum(nums[idx:n]) - sum(nums[0:idx])

        if n % 2 != 0:
            res = res + nums[idx-1]
        
        return res
