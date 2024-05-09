# https://leetcode.cn/problems/watering-plants/

class Solution:
    def wateringPlants(self, plants, capacity):
        """
        Inputs:
            plants: list[int]
            capacity: int
        Outputs:
            res: int
        """
        res = 0
        cur = capacity
        for i, p in enumerate(plants):
            if cur >= p:
                cur -= p
                res += 1
            else:
                cur = capacity - p
                res += (i+i+1)
        return res