# https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/

from collections import defaultdict

class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        position = defaultdict(list)
        for i, num in enumerate(nums):
            position[num].append(i)
        res = -1
        for pos in position.values():
            for i in range(2, len(pos)):
                d = 2 * (pos[i] - pos[i-2])
                if res < 0 or res > d:
                    res = d
        return res