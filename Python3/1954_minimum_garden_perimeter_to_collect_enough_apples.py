# https://leetcode.cn/problems/minimum-garden-perimeter-to-collect-enough-apples/

class Solution:
    def minimumPerimeter(self, neededApples):
        """
        Inputs:
            neededApples: int
        Outputs:
            res: int
        """
        num, k = 0, 0
        while num < neededApples:
            k += 1
            num += 12 * k * k
        return 8*k