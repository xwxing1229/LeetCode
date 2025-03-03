# https://leetcode.cn/problems/design-memory-allocator/

from collections import defaultdict

class Allocator:

    def __init__(self, n: int):
        self.n = n
        self.memory = [0 for _ in range(n+1)]
        self.memory[-1] = 1
        self.location = defaultdict(list)

    def allocate(self, size: int, mID: int) -> int:
        res = 0
        zeros = 0
        for i in range(self.n+1):
            if self.memory[i] == 0:
                zeros += 1
            elif zeros >= size:
                for k in range(res, res+size):
                    self.memory[k] = 1
                self.location[mID].append([res, size])
                return res
            else:
                res = i + 1
                zeros = 0
        return -1

    def freeMemory(self, mID: int) -> int:
        res = 0
        for start, size in self.location[mID]:
            res += size
            for i in range(start, start+size):
                self.memory[i] = 0
        self.location[mID].clear()
        return res


# Your Allocator object will be instantiated and called as such:
# obj = Allocator(n)
# param_1 = obj.allocate(size,mID)
# param_2 = obj.freeMemory(mID)