# https://leetcode.cn/problems/distance-between-bus-stops/

class Solution:
    def distanceBetweenBusStops(self, distance, start, destination):
        """
        Inputs:
            distance: list[int]
            start, destination: int
        Outputs:
            res: int
        """
        def distance_a2b(a, b):
            res = 0
            cur = a
            n = len(distance)
            while cur != b:
                res += distance[cur]
                cur = (cur + 1) % n
            return res
        
        return min(distance_a2b(start, destination), distance_a2b(destination, start))