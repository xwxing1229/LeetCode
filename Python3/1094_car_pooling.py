# https://leetcode.cn/problems/car-pooling/

class Solution:
    def carPooling(self, trips, capacity):
        """
        Inputs:
            trips: list[list[int]]
            capacity: int
        Outputs:
            res: bool
        """
        trips.sort(key=lambda x: x[1])
        cur = 0
        ends = []
        for i, trip in enumerate(trips):
            while ends and ends[0][0] <= trip[1]:
                cur -= heappop(ends)[1]
            cur += trip[0]
            if cur > capacity:
                return False
            
            heappush(ends, (trip[2], trip[0]))
        return True