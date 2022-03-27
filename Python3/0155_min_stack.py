# https://leetcode-cn.com/problems/min-stack/

class Solution:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        
    def push(self, x):
        """
        Inputs:
            x: int
        Outputs:
            None
        """
        if not self.stack:
            self.stack.append((x,x))
        else:
            self.stack.append((x,min(x,self.stack[-1][1])))
            
    def pop(self):
        """
        Inputs:
            None
        Outputs:
            None
        """
        self.stack.pop()
        
    def top(self):
        """
        Inputs:
            None
        Outputs:
            return int
        """
        return self.stack[-1][0]
    
    def getMin(self):
        """
        Inputs:
            None
        Outputs:
            return int
        """
        return self.stack[-1][1]
    
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()