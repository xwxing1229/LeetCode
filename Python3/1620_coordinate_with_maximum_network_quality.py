# https://leetcode.cn/problems/coordinate-with-maximum-network-quality/

class Solution:
    def bestCoordinate(self, towers, radius):
        """
        Inputs:
            towers: list[list[int]]
            radius: int
        Outputs:
            res: list[int]
        """
        xMin, xMax = towers[0][0], towers[0][0]
        yMin, yMax = towers[0][1], towers[0][1]
        for tx, ty, tq in towers:
            if tx < xMin:
                xMin = tx
            if tx > xMax:
                xMax = tx
            if ty < yMin:
                yMin = ty
            if ty > yMax:
                yMax = ty

        res = [0, 0]
        quality = 0
        for x in range(xMin, xMax+1):
            for y in range(yMin, yMax+1):
                q = 0
                for tx, ty, tq in towers:
                    dist = sqrt((x-tx)*(x-tx) + (y-ty)*(y-ty))
                    if dist <= radius:
                        q += (tq // (1 + dist))
                if q > quality:
                    res[0] = x
                    res[1] = y
                    quality = q
        return res
