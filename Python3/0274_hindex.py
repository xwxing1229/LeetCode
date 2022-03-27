# https://leetcode-cn.com/problems/h-index/

class Solution:
    def hIndex(self, citations):
        """
        Inputs:
            citations: list[int]
        Outputs:
            res: int
        """

        citations.sort()
        n = len(citations)

        res = 0
        for i in range(n):
            if n-i <= citations[i]:
                res = n - i
                break
        return res