# https://leetcode.cn/problems/final-value-of-variable-after-performing-operations/

class Solution:
    def finalValueAfterOperations(self, operations):
        """
        Inputs:
            operations: list[str]
        Outputs:
            res: int
        """
        res = 0
        for s in operations:
            if s[1] == "+":
                res += 1
            else:
                res -= 1
        return res