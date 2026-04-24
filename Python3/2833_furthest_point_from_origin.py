# https://leetcode.cn/problems/furthest-point-from-origin/

class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left, right, tmp = 0, 0, 0
        for ch in moves:
            left += (ch == "L")
            right += (ch == "R")
            tmp += (ch == "_")
        return max(left+tmp-right, right+tmp-left)