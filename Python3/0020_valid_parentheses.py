# https://leetcode-cn.com/problems/valid-parentheses/

class Solution:
    def isValid(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: bool
        """

        res = True
        m = {'}':'{', ')':'(', ']':'['}
        stack = []

        for i in s:
            if i not in m:
                stack.append(i)
            else:
                tmp = '-'
                if stack:
                    tmp = stack.pop()
                if tmp != m[i]:
                    res = False
                    break
        if stack:
            res = False
        return res