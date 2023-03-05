# https://leetcode.cn/problems/generate-random-point-in-a-circle/

class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.r, self.r_square = radius, radius * radius
        self.x, self.y = x_center, y_center

    def randPoint(self) -> List[float]:
        while True:
            x = random.uniform(-self.r, self.r)
            y = random.uniform(-self.r, self.r)
            if x * x + y * y <= self.r_square:
                return [self.x + x, self.y + y]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()