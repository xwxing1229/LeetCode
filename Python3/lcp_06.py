# https://leetcode.cn/problems/na-ying-bi/

class Solution:
    def minCount(self, coins):
        """
        Inputs:
            coins: list[int]
        Outputs:
            res: int
        """
        return sum([(c+1)//2 for c in coins])