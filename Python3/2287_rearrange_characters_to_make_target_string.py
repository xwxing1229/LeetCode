# https://leetcode.cn/problems/rearrange-characters-to-make-target-string/

class Solution:
    def rearrangeCharacters(self, s, target):
        """
        Inputs:
            s, target: str
        Outputs:
            res: int
        """
        require, cnt = dict(), dict()
        for ch in target:
            require[ch] = require.get(ch, 0) + 1
        for ch in s:
            cnt[ch] = cnt.get(ch, 0) + 1
        res = len(s) // len(target)
        for k, v in require.items():
            res = min(res, cnt.get(k,0)//v)
        return res