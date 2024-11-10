# https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row/

class Solution:
    def findWinningPlayer(self, skills, k):
        """
        Inputs:
            skills: list[int]
            k: int
        Outputs:
            res: int
        """
        win = 0
        cur, i = 0, 1
        n = len(skills)
        while win < k:
            if skills[cur] > skills[i]:
                win += 1
            else:
                win = 1
                cur = i
            i += 1
            if i == n:
                return cur
        return cur