# https://leetcode.cn/problems/random-flip-matrix/

class Solution:

    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.last_idx = m * n - 1
        self.zeros = m * n
        self.ones = set()

    def flip(self) -> List[int]:
        idx = random.randint(0, self.zeros-1)
        if idx == self.last_idx or idx in self.ones:
            while self.last_idx in self.ones:
                self.last_idx -= 1
            res = [self.last_idx // self.n, self.last_idx % self.n]
            self.last_idx -= 1            
        else:
            self.ones.add(idx)
            res = [idx // self.n, idx % self.n]
        self.zeros -= 1
        return res

    def reset(self) -> None:
        self.last_idx = self.m * self.n - 1
        self.zeros = self.m * self.n
        self.ones.clear()


# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()