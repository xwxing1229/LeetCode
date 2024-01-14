# https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/

class Solution:
    def isWinner(self, player1, player2):
        """
        Inputs:
            player1, player2: list[int]
        Outputs:
            res: int
        """
        score1, score2 = self.checkPoints(player1), self.checkPoints(player2)
        if score1 > score2:
            return 1
        elif score1 < score2:
            return 2
        else:
            return 0
        
    def checkPoints(self, player):
        n = len(player)
        if n == 1:
            return player[0]
        else:
            res = player[0] + player[1]
            if player[0] == 10:
                res += player[1]
            for i in range(2, n):
                if player[i-2] == 10 or player[i-1] == 10:
                    res += 2 * player[i]
                else:
                    res += player[i]
            return res