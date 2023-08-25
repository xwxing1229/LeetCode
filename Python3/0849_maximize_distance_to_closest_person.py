# https://leetcode.cn/problems/maximize-distance-to-closest-person/

class Solution:
    def maxDistToClosest(self, seats):
        """
        Inputs:
            seats: list[int]
        Outputs:
            res: int
        """
        i, n = 0, len(seats)
        while i < n and seats[i] == 0:
            i += 1
        res, pre = i, i
        while i < n:
            if seats[i] == 1:
                res = max(res, (i-pre)//2)
                pre = i
            i += 1
        if seats[n-1] == 0:
            res = max(res, n-1-pre)
        return res