# https://leetcode.cn/problems/longest-uncommon-subsequence-i/

class Solution:
    def findLUSlength(self, a, b):
        """
        Inputs:
            a, b: str
        Outputs:
            res: int
        """
        return max(len(a), len(b)) if a != b else -1