# https://leetcode.cn/problems/design-an-ordered-stream/

class OrderedStream:

    def __init__(self, n: int):
        self.stream = ["" for _ in range(n+1)]
        self.cur = 1
        self.n = n
        
    def insert(self, idKey, value):
        """
        Inputs:
            idKey: int
            value: str
        Outputs:
            res: list[int]
        """
        self.stream[idKey] = value
        
        res = []
        while self.cur <= self.n and self.stream[self.cur] != "":
            res.append(self.stream[self.cur])
            self.cur += 1
        return res


# Your OrderedStream object will be instantiated and called as such:
# obj = OrderedStream(n)
# param_1 = obj.insert(idKey,value)