# https://leetcode.cn/problems/minimum-distance-to-the-target-element/

class Solution:
    def getMinDistance(self, nums: list[int], target: int, start: int) -> int:
        res = len(nums)
        for i, num in enumerate(nums):
            if num == target:
                d = abs(i - start)
                if res > d:
                    res = d
                else:
                    break
        return res