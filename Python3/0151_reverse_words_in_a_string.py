# https://leetcode.cn/problems/reverse-words-in-a-string/

class Solution:
    def reverseWords(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """

        words = s.split(" ")
        res = ""
        for i in range(len(words)-1, -1, -1):
            word = words[i]
            if word != "":
                res = res + word + " "
        res = res[:-1]
        return res
