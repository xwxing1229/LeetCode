# https://leetcode.cn/problems/construct-the-rectangle/

class Solution:
    def constructRectangle(self, area):
        """
        Inputs:
            area: int
        Outputs:
            res: list[int]
        """
        width = int(sqrt(area))
        while area % width != 0:
            width -= 1
        return [area//width, width]
