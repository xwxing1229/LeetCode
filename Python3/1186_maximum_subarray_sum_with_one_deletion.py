# https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/

class Solution:
    def maximumSum(self, arr):
        """
        Inputs:
            arr: list[int]
        Outputs:
            res: int
        """
        # dp[i][0]: maximum sum until arr[i] with no element removed
        # dp[i][1]: maximum sum until arr[i] with 1 element removed
        dp = [[0,0] for i in range(len(arr))]
        dp[0][0] = arr[0]
        res = arr[0]
        for i in range(1, len(arr)):
            dp[i][0] = max(dp[i-1][0]+arr[i], arr[i])
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i])
            res = max(res, max(dp[i][0], dp[i][1]))
        return res