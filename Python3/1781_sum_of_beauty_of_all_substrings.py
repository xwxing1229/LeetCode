# https://leetcode.cn/problems/sum-of-beauty-of-all-substrings/

class Solution:
    def beautySum(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: int
        """
        res = 0
        n = len(s)
        if n <= 2:
            return res

        for i in range(n-2):
            cnt = {s[i]: 1}
            max_ = 1
            for j in range(i+1, n):
                ch = s[j]
                cnt[ch] = cnt.get(ch,0) + 1
                if max_ < cnt[ch]:
                    max_ = cnt[ch]
                res += (max_ - min(cnt.values()))
        return res