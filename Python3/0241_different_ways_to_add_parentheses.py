# https://leetcode.cn/problems/different-ways-to-add-parentheses/

class Solution:
    def diffWaysToCompute(self, expression):
        """
        Inputs:
            expression: str
        Outputs:
            res: list[int]
        """
        self.split(expression)
        res = self.computeAll(self.nums, 0)
        return res

    def split(self, expression):
        self.nums = []
        self.ops = []
        num = 0
        n = len(expression)
        for i in range(n):
            ch = expression[n]
            if ch in ['+', '-', '*']:
                self.nums.append(num)
                self.ops.append(ch)
                num = 0
            elif i == n-1:
                num = num * 10 + ord(ch) - ord('0')
                self.nums.append(num)
                num = 0
            else:
                num = num * 10 + ord(ch) - ord('0')

    def computeAll(self, nums, idx):
        if len(nums) == 1:
            return [nums[0]]

        res = []
        n = len(nums)
        for i in range(1, n-1):
            left = self.computeAll(self.nums[:i], idx)
            right = self.computeAll(self.nums[i:], idx+i)

            ch = self.ops[idx+i-1]
            for num1 in left:
                for num2 in right:
                    if ch == '+':
                        tmp = num1 + num2
                    elif ch == '-':
                        tmp = num1 - num2
                    else:
                        tmp = num1 * num2
                    res.append(tmp)
        return res