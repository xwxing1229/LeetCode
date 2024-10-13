# https://leetcode.cn/problems/minimum-number-of-refueling-stops/

class Solution:
    def minRefuelStops(self, target, startFuel, stations):
        """
        Inputs:
            target, startFuel: int
            stations: list[list[int]]
        Outputs:
            res: int
        """
        res = 0
        heap = []
        cur = startFuel
        pos_pre = 0
        stations.append([target, 0])
        for pos, fuel in stations:
            cur -= pos - pos_pre
            while heap and cur < 0:
                cur -= heapq.heappop(heap)
                res += 1
            if cur < 0:
                return -1
            heapq.heappush(heap, -fuel)
            pos_pre = pos
        return res