# https://leetcode.cn/problems/circle-and-rectangle-overlapping/

class Solution:
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        """
        Inputs:
            radius, xCenter, yCenter: int
            x1, y1, x2, y2: int
        Outputs:
            res: bool
        """
        rsq = radius * radius
        if xCenter < x1:
            if yCenter > y2:
                if self.dsquare(xCenter, yCenter, x1, y2) <= rsq:
                    return True
            elif yCenter > y1:
                if xCenter >= x1-radius:
                    return True
            else:
                if self.dsquare(xCenter, yCenter, x1, y1) <= rsq:
                    return True
        elif xCenter < x2:
            if yCenter <= y2+radius and yCenter >= y1-radius:
                return True
        else:
            if yCenter > y2:
                if self.dsquare(xCenter, yCenter, x2, y2) <= rsq:
                    return True
            elif yCenter > y1:
                if xCenter <= x2+radius:
                    return True
            else:
                if self.dsquare(xCenter, yCenter, x2, y1) <= rsq:
                    return True
        return False
    
    def dsquare(self, x1, y1, x2, y2):
        return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)