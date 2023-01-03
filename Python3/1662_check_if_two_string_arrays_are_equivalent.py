# https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/

class Solution:
    def arrayStringsAreEqual(self, word1, word2):
        """
        Inputs:
            word1: list[str]
            word2: list[str]
        Outputs:
            res: bool
        """

        idx1, idx2 = 0, 0
        i1, i2 = 0, 0
        while idx1 < len(word1) and idx2 < len(word2):
            w1, w2 = word1[idx1], word2[idx2]
            while i1 < len(w1) and i2 < len(w2):
                if w1[i1] != w2[i2]:
                    return False
                i1 += 1
                i2 += 1
            if i1 == len(w1):
                i1 = 0
                idx1 += 1
            if i2 == len(w2):
                i2 = 0
                idx2 += 1

        if idx1 - len(word1) + idx2 - len(word2) < 0:
            return False
        return True