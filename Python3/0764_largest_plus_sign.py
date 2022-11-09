# https://leetcode.cn/problems/largest-plus-sign/

class Solution:
    def orderOfLargestPlusSign(self, n, mines):
        """
        Inputs:
            n: int
            mines: list[list[int]]
        Outputs:
            res: int
        """

        # dp[i][j][k]: number of consecutive 1 along the kth direction (left,
        # right, up, down) starting from (i,j).
        # Actually we only need min(dp[i][j][0], ..., dp[i][j][3]) for each (i,j).
        dp = [[n for j in range(n)] for i in range(n)]
        s = set([(mine[0], mine[1]) for mine in mines])
        for i in range(n):
            cnt = 0 # left
            for j in range(n):
                if (i,j) in s:
                    cnt = 0
                else:
                    cnt += 1
                if dp[i][j] > cnt:
                    dp[i][j] = cnt
            cnt = 0 # right
            for j in range(n-1, -1, -1):
                if (i,j) in s:
                    cnt = 0
                else:
                    cnt += 1
                if dp[i][j] > cnt:
                    dp[i][j] = cnt
        for j in range(n):
            cnt = 0 # up
            for i in range(n):
                if (i,j) in s:
                    cnt = 0
                else:
                    cnt += 1
                if dp[i][j] > cnt:
                    dp[i][j] = cnt
            cnt = 0 # down
            for i in range(n-1, -1, -1):
                if (i,j) in s:
                    cnt = 0
                else:
                    cnt += 1
                if dp[i][j] > cnt:
                    dp[i][j] = cnt

        res = 0
        for i in range(n):
            for j in range(n):
                if dp[i][j] > res:
                    res = dp[i][j]
        return res
