# https://leetcode.cn/problems/minimum-time-to-complete-trips/

class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        """
        Inputs:
            time: list[int]
            totalTrips: int
        Outputs:
            res: int
        """
        left, right = 1, totalTrips*min(time)
        res = totalTrips
        while left <= right:
            mid = (left + right) // 2
            tmp = 0
            for t in time:
                tmp += mid // t
            if tmp >= totalTrips:
                res = mid
                right = mid - 1
            else:
                left = mid + 1
        return res