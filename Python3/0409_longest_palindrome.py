# https://leetcode.cn/problems/longest-palindrome/

class Solution:
    def longestPalindrome(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """

        cnt = dict()
        for ch in s:
            cnt[ch] = cnt.get(ch, 0) + 1

        res = 0
        for ch in cnt:
            res = res + cnt[ch] // 2 * 2
        if res < len(s):
            res = res + 1
        return res