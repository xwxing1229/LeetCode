# https://leetcode.cn/problems/count-collisions-on-a-road/

class Solution:
    def countCollisions(self, directions: str) -> int:
        n = len(directions)
        left, right = 0, n-1
        while left < n and directions[left] == "L":
            left += 1
        while right >= 0 and directions[right] == "R":
            right -= 1
        if left >= n or right < 0:
            return 0
        return right - left + 1 - directions[left: right+1].count("S")