# https://leetcode.cn/problems/walking-robot-simulation/

class Solution:
    def robotSim(self, commands: list[int], obstacles: list[list[int]]) -> int:
        obs = set()
        for o in obstacles:
            obs.add(o[0] * 60001 + o[1])
        res = 0
        px, py = 0, 0
        dx, dy = 0, 1
        for cmd in commands:
            if cmd == -2:
                dx, dy = -dy, dx
            elif cmd == -1:
                dx, dy = dy, -dx
            else:
                for i in range(cmd):
                    x, y = px + dx, py + dy
                    if x * 60001 + y in obs:
                        break
                    px, py = x, y
                    res = max(res, px * px + py * py)
        return res