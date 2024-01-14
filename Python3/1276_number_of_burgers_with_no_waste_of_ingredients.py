# https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/

class Solution:
    def numOfBurgers(self, tomatoSlices, cheeseSlices):
        """
        Inputs:
            tomatoSlices, cheeseSlices: int
        Outputs:
            res: list[int]
        """
        x = (tomatoSlices - 2*cheeseSlices) // 2
        y = (4*cheeseSlices - tomatoSlices) // 2
        if x >= 0 and y >= 0 and 4*x+2*y == tomatoSlices and x + y ==cheeseSlices:
            return [x, y]
        else:
            return []