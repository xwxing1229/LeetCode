# https://leetcode.cn/problems/build-an-array-with-stack-operations/

class Solution:
    def buildArray(self, target, n):
        """
        Inputs:
            target: list[int]
            n: int
        Outputs:
            res: list[str]
        """

        res = []
        i = 1
        for num in target:
            while num != i:
                res.append("Push")
                res.append("Pop")
                i = i + 1
            res.append("Push")
            i = i + 1
        return res