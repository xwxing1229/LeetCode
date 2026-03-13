# https://leetcode.cn/problems/minimum-number-of-seconds-to-make-mountain-height-zero/

import math

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: list[int]) -> int:
        def check(t):
            s = 0
            for w in workerTimes:
                s += int(math.sqrt(2 * t / w + 0.25) - 0.5)
                if s >= mountainHeight:
                    return True
            return False
        
        left = 0
        right = mountainHeight * (mountainHeight + 1) * min(workerTimes) // 2
        res = right
        while left <= right:
            mid = left + (right - left) // 2
            if check(mid):
                res = mid
                right = mid - 1
            else:
                left = mid + 1
        return res