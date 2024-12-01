# https://leetcode.cn/problems/find-the-number-of-winning-players/

class Solution:
    def winningPlayerCount(self, n, pick):
        """
        Inputs:
            n: int
            pick: list[list[int]]
        Outputs:
            res: int
        """
        res = 0
        win = [0 for _ in range(n)]
        players = [defaultdict(int) for _ in range(n)]
        for a, b in pick:
            if win[a]:
                continue
            players[a][b] += 1
            if players[a][b] > a:
                res += 1
                win[a] = 1
        return res