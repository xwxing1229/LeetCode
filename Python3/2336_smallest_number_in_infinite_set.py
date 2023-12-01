# https://leetcode.cn/problems/smallest-number-in-infinite-set/

class SmallestInfiniteSet:

    def __init__(self):
        self.removed = set()
        self.min_val = 1

    def popSmallest(self) -> int:
        self.removed.add(self.min_val)
        min_val = self.min_val
        while self.min_val in self.removed:
            self.min_val += 1
        return min_val

    def addBack(self, num: int) -> None:
        if num in self.removed:
            self.removed.remove(num)
        self.min_val = min(self.min_val, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)