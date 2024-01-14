# https://leetcode.cn/problems/buy-two-chocolates/

class Solution:
    def buyChoco(self, prices, money):
        """
        Inputs:
            prices: list[int]
            money: int
        Outputs:
            res: int
        """
        a = min(prices[0], prices[1])
        b = max(prices[0], prices[1])
        for i in range(2, len(prices)):
            price = prices[i]
            if a > price:
                b = min(b, a)
                a = price
            else:
                b = min(b, price)
        tmp = a + b
        if tmp <= money:
            return money - tmp
        else:
            return money