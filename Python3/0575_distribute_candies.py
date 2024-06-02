# https://leetcode.cn/problems/distribute-candies/

class Solution:
    def distributeCandies(self, candyType):
        """
        Inputs:
            candyType: list[int]
        Outputs:
            res: int
        """
        
        candyType.sort()
        res = 1
        n = len(candyType)
        pre = candyType[0]
        i, half = 1, n//2
        while i < n and res < half:
            candy = candyType[i]
            if candy != pre:
                res += 1
                pre = candy
        return res