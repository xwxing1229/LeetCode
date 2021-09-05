# https://leetcode-cn.com/problems/jump-game-ii/
class Solution:
    def jump(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        n = len(nums)
        if n == 1 or nums[0] == 0:
            return 0

        # dp[i]: minimum number of jumps required at position i
        dp = [n for _ in range(n)]
        for i in range(n-2, -1, -1):
            if nums[i] >= n-1-i:
                dp[i] = 1
            else:
                jump_to = min(n-1, i+nums[i])
                dp[i] = 1 + min(dp[i: jump_to+1])
                
        return dp[0]