# https://leetcode.cn/problems/moving-stones-until-consecutive/

class Solution:
    def numMovesStones(self, a, b, c):
        """
        Inputs:
            a, b, c: int
        Outputs:
            res: list[int]
        """
        pos = [a, b, c]
        pos.sort()
        if pos[1] - pos[0] == 1:
            if pos[2] - pos[1] == 1:
                min_move = 0
            else:
                min_move = 1
        elif pos[1] - pos[0] == 2:
            min_move = 1
        else:
            if pos[2] - pos[1] <= 2:
                min_move = 1
            else:
                min_move = 2
        max_move = pos[2] - pos[0] - 2
        res = [min_move, max_move]
        return res