# https://leetcode.cn/problems/online-stock-span/

class StockSpanner:

    def __init__(self):
        self.stack = [[-1, float("inf")]]
        self.idx = -1

    def next(self, price):
        """
        Inputs:
            price: int
        Outputs:
            res: int
        """
        self.idx += 1
        while price >= self.stack[-1][1]:
            self.stack.pop()
        self.stack.append([self.idx, price])
        res = self.idx - self.stack[-2][0]
        return res

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
