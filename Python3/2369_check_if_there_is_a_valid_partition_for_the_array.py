# https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution:
    def validPartition(self, nums):
        """
        Inputs:
            nums: list[int]
        Outputs:
            res: bool
        """
        n = len(nums)
        dp = [False for _ in range(n)]
        if n >= 2 and nums[0] == nums[1]:
            dp[1] = True
        if n >= 3 and self.valid3(nums[0], nums[1], nums[2]):
            dp[2] = True
        if n >= 4 and nums[0] == nums[1] and nums[2] == nums[3]:
            dp[3] = True

        for i in range(4, n):
            if dp[i-2] and nums[i-1] == nums[i]:
                dp[i] = True
            elif dp[i-3] and self.valid3(nums[i-2], nums[i-1], nums[i]):
                dp[i] = True
        return dp[n-1]
    
    def valid3(self, num1, num2, num3):
        if (num1 == num2 and num2 == num3) or (num2 - num1 == 1 and num3 - num2 == 1):
            return True
        else:
            return False