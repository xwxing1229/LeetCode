# https://leetcode.cn/problems/stock-price-fluctuation/

class StockPrice:

    def __init__(self):
        self.cur = 0
        self.stock = dict()
        self.pq_max = []
        self.pq_min = []

    def update(self, timestamp: int, price: int) -> None:
        self.cur = max(self.cur, timestamp)
        self.stock[timestamp] = price
        heappush(self.pq_max, (-price, timestamp))
        heappush(self.pq_min, (price, timestamp))

    def current(self) -> int:
        return self.stock[self.cur]

    def maximum(self) -> int:
        while True:
            price, timestamp = self.pq_max[0]
            if self.stock[timestamp] == -price:
                return -price
            heappop(self.pq_max)

    def minimum(self) -> int:
        while True:
            price, timestamp = self.pq_min[0]
            if self.stock[timestamp] == price:
                return price
            heappop(self.pq_min)

# Your StockPrice object will be instantiated and called as such:
# obj = StockPrice()
# obj.update(timestamp,price)
# param_2 = obj.current()
# param_3 = obj.maximum()
# param_4 = obj.minimum()