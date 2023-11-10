# https://leetcode.cn/problems/can-place-flowers/

class Solution:
    def canPlaceFlowers(self, flowerbed, n):
        """
        Inputs:
            flowerbed: list[int]
            n: int
        Outputs:
            res: bool
        """
        num, pre = 0, 0
        for i in range(len(flowerbed)-1):
            cur = flowerbed[i]
            if pre == 0 and cur == 0 and flowerbed[i+1] == 0:
                num += 1
                pre = 1
            else:
                pre = cur
        if pre == 0 and flowerbed[-1] == 0:
            num += 1
        return num >= n