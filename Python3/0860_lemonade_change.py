# https://leetcode.cn/problems/lemonade-change/

class Solution:
    def lemonadeChange(self, bills):
        """
        Inputs:
            bills: list[int]
        Outputs:
            res: bool
        """
        c5, c10 = 0, 0
        res = True
        for bill in bills:
            if bill == 5:
                c5 += 1
            elif bill == 10:
                c5 -= 1
                c10 += 1
            else:
                if c10 > 0:
                    c10 -= 1
                    c5 -= 1
                else:
                    c5 -= 3
            if c5 < 0 or c10 < 0:
                res = False
                break
        return res
