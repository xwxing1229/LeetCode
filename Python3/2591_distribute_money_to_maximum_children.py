# https://leetcode.cn/problems/distribute-money-to-maximum-children/

class Solution:
    def distMoney(self, money, children):
        """
        Inputs:
            money, children: int
        Outputs:
            res: int
        """
        money -= children
        if money < 0:
            return -1

        res = money // 7
        rem = money % 7
        if res > children:
            res = children - 1
        elif res == children:
            if rem != 0:
                res -= 1
        else:
            if rem == 3 and children - res == 1:
                res -= 1
        return res