# https://leetcode.cn/problems/evaluate-reverse-polish-notation/

class Solution:
    def evalRPN(self, tokens):
        """
        Inputs:
            tokens: list[str]
        Outputs:
            res: int
        """

        nums = []
        ops = ["+", "-", "*", "/"]
        for token in tokens:
            if token not in ops:
                num = int(token)
                nums.append(num)
            else:
                second = nums.pop()
                first = nums.pop()
                if token == "+":
                    tmp = first + second
                elif token == "-":
                    tmp = first - second
                elif token == "*":
                    tmp = first * second
                else:
                    tmp = int(first / second)
                nums.append(tmp)

        return nums[0]

solu = Solution()
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
print(solu.evalRPN(tokens))