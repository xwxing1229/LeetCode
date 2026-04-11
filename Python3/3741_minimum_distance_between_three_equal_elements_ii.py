# https://leetcode.cn/problems/minimum-distance-between-three-equal-elements-ii/

class Solution:
    def minimumDistance(self, nums: list[int]) -> int:
        res = -1
        n = len(nums)
        position = [[-1, -1] for _ in range(n+1)]
        for i, num in enumerate(nums):
            if position[num][0] >= 0:
                d = i - position[num][0]
                if res < 0 or res > d:
                    res = d
            position[num][0] = position[num][1]
            position[num][1] = i
        return 2 * res if res > 0 else -1