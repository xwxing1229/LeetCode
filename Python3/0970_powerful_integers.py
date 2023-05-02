# https://leetcode.cn/problems/powerful-integers/

class Solution:
    def powerfulIntegers(self, x, y, bound):
        """
        Inputs:
            x, y, bound: int
        Outputs:
            res: list[int]
        """
        powx, powy = [1], [1]
        endx, endy = False, False
        while not (endx and endy):
            if x > 1 and powx[-1] < bound / x:
                powx.append(powx[-1] * x)
            else:
                endx = True
            if y > 1 and powy[-1] < bound / y:
                powy.append(powy[-1] * y)
            else:
                endy = True
        
        res = set()
        for i in powx:
            for j in powy:
                if i <= bound - j:
                    res.add(i + j)

        return list(res)