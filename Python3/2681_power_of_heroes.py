# https://leetcode.cn/problems/power-of-heroes/

class Solution:
    def sumOfPower(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: int
        """

        # Sort nums. Let dp[i] be the total value of the subsequences
        # that end with nums[i]. Then
        #   dp[i] = nums[i]^2 * (cur + nums[i]),
        # where
        #   cur = dp[i-1]/(nums[i-1]^2) + ... + dp[0]/(nums[0]^2).
        # Then res = sum(dp[i]) % 1000000007.
        mod = 1000000007
        nums.sort()
        cur, cumsum = 0, 0
        res = 0
        for i in range(len(nums)):
            cur = cumsum + nums[i]
            val = nums[i] * nums[i] * cur % mod
            cumsum = (cumsum + cur) % mod

            res = (res + val) % mod
            
        return res