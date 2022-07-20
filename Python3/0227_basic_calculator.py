# https://leetcode.cn/problems/basic-calculator-ii/

class Solution:
    def calculate(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        stack = []
        n = len(s)
        num = 0
        preOp = '+'
        for i in range(n):
            if s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
                
            if s[i] in "+-*/" or i == n-1:
                if preOp == '+':
                    stack.append(num)
                elif preOp == '-':
                    stack.append(-num)
                elif preOp == '*':
                    last = stack.pop()
                    stack.append(last * num)
                else:
                    last = stack.pop()
                    stack.append(int(last / num))
                num = 0
                preOp = s[i]
        return sum(stack)
