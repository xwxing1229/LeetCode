# https://leetcode.cn/problems/implement-queue-using-stacks/

class MyQueue:

    def __init__(self):
        self.stk1 = []
        self.stk2 = []

    def push(self, x: int) -> None:
        n = len(self.stk1)
        for i in range(n):
            num = self.stk1.pop()
            self.stk2.append(num)
        
        self.stk1.append(x)
        for i in range(n):
            num = self.stk2.pop()
            self.stk1.append(num)

    def pop(self) -> int:
        return self.stk1.pop()

    def peek(self) -> int:
        return self.stk1[-1]

    def empty(self) -> bool:
        return not self.stk1


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()