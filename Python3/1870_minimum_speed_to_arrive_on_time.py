# https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/

class Solution:
    def minSpeedOnTime(self, dist, hour):
        """
        Inputs:
            dist: list[int]
            hour: float
        Outputs:
            res: int
        """
        n = len(dist)
        if hour <= n-1:
            return -1
        
        left, right = 1, max(dist)
        if hour != int(hour):
            right = max(right, int(dist[-1] / (hour - int(hour))) + 1)
        res = right
        while left <= right:
            mid = (left + right) // 2
            total = 0
            for i in range(n-1):
                t = dist[i] / mid
                total += int(t)
                if t != int(t):
                    total += 1
            total += dist[-1] / mid

            if total <= hour:
                res = mid
                right = mid - 1
            else:
                left = mid + 1
        return res