# https://leetcode-cn.com/problems/find-the-difference/

class Solution:
    def findTheDifference(self, s, t):
        """
        Inputs:
            s: str
            t: str
        Outputs:
            res: str
        """

        count_s = 0
        for i in s:
            count_s = count_s + ord(i)

        count_t = 0
        for i in t:
            count_t = count_t + ord(i)

        return chr(count_t - count_s)