# https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/

class Solution:
    def minimumRounds(self, tasks):
        """
        Inputs:
            tasks: list[int]
        Outputs:
            res: int
        """
        n = len(tasks)
        tasks.sort()
        dp = [n for _ in range(n+2)]
        dp[0] = 0
        dp[1] = 0
        if n > 1 and tasks[1] == tasks[0]:
            dp[3] = 1
        if n > 2 and tasks[2] == tasks[1] and tasks[1] == tasks[0]:
            dp[4] = 1
        for i in range(2, n):
            if tasks[i] != tasks[i-1]:
                continue
            dp[i+2] = min(dp[i+2], dp[i] + 1)
            if tasks[i] == tasks[i-2]:
                dp[i+2] = min(dp[i+2], dp[i-1]+1)
        return dp[-1] if dp[-1] != n else -1