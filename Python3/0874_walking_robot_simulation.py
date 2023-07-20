# https://leetcode.cn/problems/walking-robot-simulation/

class Solution:
    def robotSim(self, commands, obstacles):
        """
        Inputs:
            commands: list[int]
            obstacles: list[list[int]]
        Outputs:
            res: int
        """
        obs = set()
        for o in obstacles:
            obs.add(o[0] + o[1] * 60001)
        res = 0
        px, py = 0, 0
        dx, dy = 0, 1
        for command in commands:
            if command == -2:
                tmp = dx
                dx = -dy
                dy = tmp
            elif command == -1:
                tmp = dx
                dx = dy
                dy = -tmp
            else:
                for i in range(command):
                    x, y = px + dx, py + dy
                    if x + y * 60001 in obs:
                        break
                    px, py = x, y
                    res = max(res, px * px + py * py)
        return res