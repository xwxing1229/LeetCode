# https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

class Solution:
    def findLUSlength(self, strs):
        """
        Inputs:
            strs: list[str]
        Outputs:
            res: int
        """
        res = -1
        n = len(strs)
        for i, s in enumerate(strs):
            valid = True
            for j in range(n):
                if i == j:
                    continue
                if self.isSubseq(strs[j], s):
                    valid = False
                    break
            if valid:
                res = max(res, len(s))
        return res
    
    def isSubseq(self, s1, s2):
        # Check if s2 is a subsequence of s1.
        i1, i2 = 0, 0
        n1, n2 = len(s1), len(s2)
        for i1 in range(n1):
            if s1[i1] == s2[i2]:
                i2 += 1
            if i2 == n2:
                return True
        return False