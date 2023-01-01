# https://leetcode.cn/problems/first-letter-to-appear-twice/

class Solution:
    def repeatedCharacter(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        cnt = [0 for i in range(26)]
        for ch in s:
            if cnt[ord(ch) - ord("a")]:
                return ch
            cnt[ord(ch) - ord("a")] = 1
        return "-"