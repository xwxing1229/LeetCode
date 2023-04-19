# https://leetcode.cn/problems/partition-array-for-maximum-sum/

class Solution:
    def maxSumAfterPartitioning(self, arr, k):
        """
        Inputs:
            arr: list[int]
            k: int
        Outputs:
            res: int
        """
        # For i = 0, 1 ,..., k-1,
        #   dp[i] = x * (i+1),
        # where x = max(arr[0], ..., arr[i]).
        # For i = k, k+1, ..., n-1,
        #   dp[i] = max(dp[j] + x * (i-j)),
        # where x = max(arr[j+1], ..., arr[i]) for j = i-k+1, ..., i-1.
        n = len(arr)
        dp = [0 for _ in range(n)]
        max_cur = arr[0]
        for i in range(k):
            if max_cur < arr[i]:
                max_cur = arr[i]
            dp[i] = max_cur * (i + 1)

        for i in range(k, n):
            max_cur = arr[i] # maximum in arr[i-k+1], ..., arr[i]
            dp[i] = dp[i-1] + arr[i]
            for j in range(k):
                if max_cur < arr[i-j]:
                    max_cur = arr[i-j]
                tmp = dp[i-j-1] + max_cur * (j+1)
                if tmp > dp[i]:
                    dp[i] = tmp
        return dp[n-1]
