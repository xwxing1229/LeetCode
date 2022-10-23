# https://leetcode.cn/problems/merge-strings-alternately/

class Solution:
    def mergeAlternately(self, word1, word2):
        """
        Inputs:
            word1: str
            word2: str
        Outputs:
            res: str
        """
        res = ""
        n_word1, n_word2 = len(word1), len(word2)
        idx1, idx2 = 0, 0
        while idx1 < n_word1 and idx2 < n_word2:
            res += word1[idx1]
            res += word2[idx2]
            idx1 += 1
            idx2 += 1
        if idx1 < n_word1:
            res += word1[idx1:]
        if idx2 < n_word2:
            res += word2[idx2:]

        return res