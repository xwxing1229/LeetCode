# https://leetcode.cn/problems/circular-sentence/

class Solution:
    def isCircularSentence(self, sentence):
        """
        Inputs:
            sentence: str
        Outputs:
            res: bool
        """
        for i, ch in enumerate(sentence):
            if ch == " ":
                if sentence[i-1] != sentence[i+1]:
                    return False
        if sentence[0] != sentence[-1]:
            return False
        return True