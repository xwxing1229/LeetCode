# https://leetcode.cn/problems/number-of-orders-in-the-backlog/

class Solution:
    def getNumberOfBacklogOrders(self, orders):
        """
        Inputs:
            orders: list[list[int]]
        Outputs:
            res: int
        """
        buys, sells = [], []
        for order in orders:
            price, n = order[0], order[1]
            if order[2] == 0:
                while n and sells and price >= sells[0][0]:
                    sell = heappop(sells)
                    if n >= sell[1]:
                        n -= sell[1]
                    else:
                        sell[1] -= n
                        heappush(sells, sell)
                        n = 0
                if n:
                    heappush(buys, [-price, n])
            else:
                while n and buys and price <= -buys[0][0]:
                    buy = heappop(buys)
                    if n >= buy[1]:
                        n -= buy[1]
                    else:
                        buy[1] -= n
                        heappush(buys, buy)
                        n = 0
                if n:
                    heappush(sells, [price, n])
        res = 0
        for buy in buys:
            res = (res + buy[1]) % 1000000007
        for sell in sells:
            res = (res + sell[1]) % 1000000007
        return res
