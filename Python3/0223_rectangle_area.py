# https://leetcode.cn/problems/rectangle-area/

class Solution:
    def computeArea(self, ax1, ay1, ax2, ay2, bx1, by1, bx2, by2):
        """
        Inputs:
            ax1, ..., by2: int
        Outputs:
            res: int
        """
        
        area_a = (ax2 - ax1) * (ay2 - ay1)
        area_b = (bx2 - bx1) * (by2 - by1)
        inter_x = min(ax2, bx2) - max(ax1, bx1)
        inter_y = min(ay2, by2) - max(ay1, by1)
        return area_a + area_b - max(0, inter_x) * max(0, inter_y)