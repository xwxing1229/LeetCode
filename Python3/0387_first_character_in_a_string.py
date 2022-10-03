# https://leetcode.cn/problems/first-unique-character-in-a-string/

class Solution:
    def firstUniqChar(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        cnt = [0 for _ in range(26)]
        for ch in s:
            cnt[ord(ch) - ord('a')] = cnt[ord(ch) - ord('a')] + 1
        for i in range(len(s)):
            if cnt[ord(s[i]) - ord('a')] == 1:
                return i
        return -1
