# https://leetcode.cn/problems/number-of-paths-with-max-score/

class Solution:
    def pathsWithMaxScore(self, board: list[str]) -> list[int]:
        mod = int(1e9) + 7
        direction = [[0,1], [1,0], [1,1]]
        n = len(board)
        dp = [[[-1, -1] for _ in range(n)] for _ in range(n)]
        dp[-1][-1] = [0, 1]
        for i in range(n-2, -1, -1):
            ch = board[i][-1]
            if ch == "X":
                break
            dp[i][-1][0] = dp[i+1][-1][0] + int(ch)
            dp[i][-1][1] = 1
        for j in range(n-2, -1, -1):
            ch = board[-1][j]
            if ch == "X":
                break
            dp[-1][j][0] = dp[-1][j+1][0] + int(ch)
            dp[-1][j][1] = 1
        for i0 in range(n-2, -1, -1):
            for j0 in range(n-2, -1, -1):
                ch = board[i0][j0]
                if ch == "X":
                    continue
                tmp = -1
                for di, dj in direction:
                    i, j = i0 + di, j0 + dj
                    tmp = max(tmp, dp[i][j][0])
                if tmp < 0:
                    continue
                dp[i0][j0] = [tmp, 0]
                if ch != "E":
                    dp[i0][j0][0] += int(ch)
                for di, dj in direction:
                    i, j = i0 + di, j0 + dj
                    if tmp == dp[i][j][0]:
                        dp[i0][j0][1] = (dp[i0][j0][1] + dp[i][j][1]) % mod
        return [max(0, dp[0][0][0]), max(0, dp[0][0][1])]