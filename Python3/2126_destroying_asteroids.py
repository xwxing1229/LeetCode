# https://leetcode.cn/problems/destroying-asteroids/

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: list[int]) -> bool:
        asteroids.sort()
        curr = mass
        for a in asteroids:
            if curr < a:
                return False
            curr += a
        return True