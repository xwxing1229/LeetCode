# https://leetcode.cn/problems/number-of-different-integers-in-a-string/

class Solution:
    def numDifferentIntegers(self, word):
        """
        Input:
            word: str
        Outputs:
            res: int
        """

        num = ""
        s = set()
        word += "a"
        for ch in word:
            if ch.isdigit():
                if num == "0":
                    num = ch
                else:
                    num += ch
            elif num != "":
                s.add(num)
                num = ""
        return len(s)