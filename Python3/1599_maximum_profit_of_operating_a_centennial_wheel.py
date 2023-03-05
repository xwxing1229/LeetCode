# https://leetcode.cn/problems/maximum-profit-of-operating-a-centennial-wheel/

class Solution:
    def minOperationsMaxProfit(self, customers, boardingCost, runningCost):
        """
        Inputs:
            customers: list[int]
            boardingCost, runningCost: int
        Outputs:
            res: int
        """
        if 4 * boardingCost <= runningCost:
            return -1
        
        res, op = -1, 0
        profit, profit_max = 0, 0
        waiting = 0
        for customer in customers:
            waiting += customer
            board = min(4, waiting)
            profit += (board * boardingCost - runningCost)
            op += 1
            if profit > profit_max:
                res = op
                profit_max = profit
            waiting -= board
        
        if waiting > 4 or waiting * boardingCost > runningCost:
            res = op + waiting // 4
            waiting %= 4
        if waiting * boardingCost > runningCost:
            res += 1
        return res