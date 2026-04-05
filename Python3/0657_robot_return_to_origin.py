# https://leetcode.cn/problems/robot-return-to-origin/

class Solution:
    def judgeCircle(self, moves: str) -> bool:
        h, v = 0, 0
        for ch in moves:
            if ch == "R":
                h += 1
            elif ch == "L":
                h -= 1
            elif ch == "D":
                v += 1
            else:
                v -= 1
        return h == 0 and v == 0