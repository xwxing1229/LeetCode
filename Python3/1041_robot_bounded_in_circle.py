# https://leetcode.cn/problems/robot-bounded-in-circle/

class Solution:
    def isRobotBounded(self, instructions):
        """
        Inputs:
            instructions: str
        Outputs:
            res: bool
        """
        pos = [0, 0]
        dir = [0, 1]
        for ch in instructions:
            if ch == "G":
                pos[0] += dir[0]
                pos[1] += dir[1]
            elif ch == "L":
                tmp = dir[0]
                dir[0] = -dir[1]
                dir[1] = tmp
            else:
                tmp = dir[0]
                dir[0] = dir[1]
                dir[1] = -tmp
        if (pos[0] == 0 and pos[1] == 0) or dir[0] != 0 or dir[1] != 1:
            return True
        else:
            return False