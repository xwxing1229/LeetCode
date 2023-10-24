# https://leetcode.cn/problems/queens-that-can-attack-the-king/

class Solution:
    def queensAttacktheKing(self, queens, king):
        """
        Inputs:
            queens: list[list[int]]
            king: list[int]
        Outputs:
            res: list[list[int]]
        """
        res = []

        dirs = [[-1,-1], [-1,0], [-1,1], [0,-1], [0,1], [1,-1], [1,0], [1,1]]
        valid = [1 for i in range(8)]
        s = set()
        for queen in queens:
            s.add(8*queen[0] + queen[1])
        step = 1
        while step < 8:
            for i in range(8):
                if not valid[i]:
                    continue
                d = dirs[i]
                cur = [king[0]+step*d[0], king[1]+step*d[1]]
                if cur[0] < 0 or cur[0] >= 8 or cur[1] < 0 or cur[1] >= 8:
                    valid[i] = 0
                elif (8*cur[0]+cur[1]) in s:
                    res.append(cur)
                    valid[i] = 0
            step += 1
        return res