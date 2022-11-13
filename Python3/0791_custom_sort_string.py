# https://leetcode.cn/problems/custom-sort-string/

class Solution:
    def customSortString(self, order, s):
        """
        Inputs:
            order: str
            s: str
        Outputs:
            res: str
        """
        
        cnt = [0 for _ in range(26)]
        for ch in s:
            cnt[ord(ch) - ord("a")] += 1
            
        res = ""
        for ch in order:
            res += (ch * cnt[ord(ch) - ord("a")])
            cnt[ord(ch) - ord("a")] = 0
        for i, k in enumerate(cnt):
            res += (chr(ord("a")+i) * k)
        return res