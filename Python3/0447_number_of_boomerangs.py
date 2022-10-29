# https://leetcode.cn/problems/number-of-boomerangs/

class Solution:
    def numberOfBoomerangs(self, points):
        """
        Inputs:
            points: list[list[int]]
        Outputs:
            res: int
        """

        res = 0
        for p in points:
            cnt = dict()
            for q in points:
                dist = (p[0]-q[0]) * (p[0]-q[0]) + (p[1]-q[1]) * (p[1]-q[1])
                cnt[dist] = cnt.get(dist,0) + 1

            for k, v in cnt.items():
                res += v * (v-1)
        return res