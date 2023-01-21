# https://leetcode.cn/problems/minimum-sideway-jumps/

class Solution:
    def minSideJumps(self, obstacles):
        """
        Inputs:
            obstacles: list[int]
        Outputs:
            res: int
        """
        n = len(obstacles)
        dp_pre = [1,0,1]
        for i in range(1, n):
            dp = [n,n,n]
            obs = obstacles[i]
            for lane in range(3):
                if obs == lane + 1:
                    continue
                for other in range(3):
                    if other == lane and dp_pre[lane] < n:
                        dp[lane] = dp_pre[lane]
                    elif obs == other + 1 and obstacles[i-1] == lane + 1:
                        dp[lane] = min(dp[lane], dp_pre[other]+2)
                    else:
                        dp[lane] = min(dp[lane], dp_pre[other]+1)
            for lane in range(3):
                dp_pre[lane] = dp[lane]
        return min(dp_pre)