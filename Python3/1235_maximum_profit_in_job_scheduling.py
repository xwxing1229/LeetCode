# https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

class Solution:
    def jobScheduling(self, startTime, endTime, profit):
        """
        Inputs:
            startTime: list[int]
            endTime: list[int]
            profit: list[int]
        Outputs:
            res: int
        """

        # dp[i]: maximum profit until the ith job (the ith job is not necessarily selected).
        # Sort the lists based on endTime. Then
        # dp[i] = max(dp[i-1], profit[i] + dp[k])
        # where endTime[k] <= startTime[i].
        n = len(startTime)
        idxs = [i for i in range(n)]
        idxs.sort(key=lambda x: endTime[x])
        dp = [profit[idxs[0]] for i in range(n)]
        for i in range(1, n):
            left, right = 0, i-1
            start_i = startTime[idxs[i]]
            while left <= right:
                mid = left + (right - left) // 2
                if endTime[idxs[mid]] <= start_i:
                    left = mid + 1
                else:
                    right = mid - 1
            
            if left == 0:
                tmp = profit[idxs[i]]
            else:
                tmp = dp[left-1] + profit[idxs[i]]
                
            if tmp > dp[i-1]:
                dp[i] = tmp
            else:
                dp[i] = dp[i-1]
            
        return dp[n-1]