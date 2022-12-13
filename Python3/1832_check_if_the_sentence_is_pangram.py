# https://leetcode.cn/problems/check-if-the-sentence-is-pangram/

class Solution:
    def checkIfPangram(self, sentence):
        """
        Inputs:
            sentence: str
        Outputs:
            res: bool
        """
        cnt = [0 for _ in range(26)]
        for ch in sentence:
            cnt[ord(ch) - ord("a")] = 1
        res = True
        for i in cnt:
            if i != 1:
                res = False
                break
        return res