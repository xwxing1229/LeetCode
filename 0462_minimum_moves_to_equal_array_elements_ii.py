# https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution:
    def minMoves2(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Can be proved.
        n = len(score)
        nums.sort()
        idx = (n+1) // 2
        res = sum(nums[idx:n]) - sum(nums[0:idx])

        if n % 2 != 0:
            res = res + nums[idx-1]
        
        return res