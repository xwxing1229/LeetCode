# https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/

class Solution:
    def getLongestSubsequence(self, words, groups):
        """
        Inputs:
            words: list[str]
            groups: list[int]
        Outputs:
            res: list[str]
        """
        def getValidSubsequence(target:int):
            res = []
            for i, group in enumerate(groups):
                if group == target:
                    res.append(words[i])
                    target = 1 - target
            return res
        
        tmp1, tmp2 = getValidSubsequence(0), getValidSubsequence(1)
        res = tmp1 if len(tmp1) > tmp2 else tmp2
        return res