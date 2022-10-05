# https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/

class Solution:
    def longestSubstring(self, s, k):
        """
        Inputs:
            s: str
            k: int
        Outputs:
            res: int
        """

        if len(s) < k:
            return 0
        
        res = 0

        cnt = dict()
        for ch in s:
            cnt[ch] = cnt.get(ch, 0) + 1

        flag = True
        for ch in cnt:
            if cnt[ch] < k:
                sp = s.split(ch)
                for s_sub in sp:
                    res = max(res, self.longestSubstring(s_sub, k))
                return res
                
        return len(s)
