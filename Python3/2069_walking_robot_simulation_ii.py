# https://leetcode.cn/problems/walking-robot-simulation-ii/

class Robot:

    def __init__(self, width: int, height: int):
        self.pos = [0, 0]
        self.pos_lim = [width-1, height-1]
        self.perimeter = 2 * width + 2 * height - 4
        self.dir = [1, 0]
        self.dir_names = ["East", "North", "West", "South"]
        self.dir_id = 0

    def step(self, num: int) -> None:
        if num > self.perimeter:
            num %= self.perimeter
            if num == 0:
                num = self.perimeter
                
        while num > 0:
            if self.dir[0] == 1:
                move = self.pos_lim[0] - self.pos[0]
            elif self.dir[0] == -1:
                move = self.pos[0]
            elif self.dir[1] == 1:
                move = self.pos_lim[1] - self.pos[1]
            else:
                move = self.pos[1]
            move = min(move, num)
            self.pos[0] += move * self.dir[0]
            self.pos[1] += move * self.dir[1]
            if move < num:
                self.dir[0], self.dir[1] = -self.dir[1], self.dir[0]
                self.dir_id = (self.dir_id + 1) % 4
                
            num -= move

    def getPos(self) -> list[int]:
        return self.pos

    def getDir(self) -> str:
        return self.dir_names[self.dir_id]


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()