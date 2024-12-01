# https://leetcode.cn/problems/snake-in-matrix/

class Solution:
    def finalPositionOfSnake(self, n, commands):
        """
        Inputs:
            n: int
            commands: list[str]
        Outputs:
            res: int
        """
        i, j = 0, 0
        for cmd in commands:
            if cmd == "UP":
                i -= 1
            elif cmd == "DOWN":
                i += 1
            elif cmd == "LEFT":
                j -= 1
            else:
                j += 1
        res = i * n + j
        return res
