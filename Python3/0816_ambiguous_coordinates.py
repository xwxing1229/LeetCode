# https://leetcode.cn/problems/ambiguous-coordinates/

class Solution:
    def ambiguousCoordinates(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: list[str]
        """
        res = []
        n = len(s)
        for i in range(2, n-1):
            sub1, sub2 = s[1: i], s[i: n-1]
            n1, n2 = len(sub1), len(sub2)
            for i1 in range(1, n1+1): # x in coordinate (x,y)
                if not self.isValid(sub1[0: i1]):
                    continue
                if i1 < n1 and not self.isValid(sub1[i1: n1], False):
                    continue
                coord_x = sub1[0: i1]
                if i1 < n1:
                    coord_x += ("." + sub1[i1: n1])

                for i2 in range(1, n2+1): # y in coordinate (x,y)
                    if not self.isValid(sub2[0: i2]):
                        continue
                    if i2 < n2 and not self.isValid(sub2[i2: n2], False):
                        continue
                    coord_y = sub2[0: i2]
                    if i2 < n2:
                        coord_y += ("." + sub2[i2: n2])

                    res.append("("+coord_x+", "+coord_y+")")
        return res

    def isValid(self, cur, isInt=True):
        """
        Inputs:
            cur: str
            isInt: bool, if cur is the integer part or the fraction part
        Outputs:
            res: bool
        """
        n = len(cur)
        if (n > 1) and (cur.count("0") == n):
            return False

        if isInt:
            if (n > 1) and (cur[0] == "0"):
                return False
        else:
            if cur[-1] == "0":
                return False
        return True
