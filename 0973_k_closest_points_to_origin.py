# https://leetcode-cn.com/problems/k-closest-points-to-origin/
class Solution:
    def kClosest(self, points, k):
        """
        Inputs:
            points: list[list[int]]
            k: int
        Outputs:
            res: list[list[int]]
        """

        count = {}
        for point in points:
            dis = point[0]**2 + point[1]**2
            count[(point[0], point[1])] = dis
        
        count = sorted(count.items(), key=lambda item:item[1])
        res = []
        num = 0
        while num < k:
            res.append([count[num][0][0], count[num][0][1]])
            num = num + 1
        
        return res