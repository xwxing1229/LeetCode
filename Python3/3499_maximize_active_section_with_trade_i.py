# https://leetcode.cn/problems/maximize-active-section-with-trade-i/

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        n = len(s)
        cnt1 = 0
        prev0, cnt0_max = -n, 0
        cnt = 0
        for i, ch in enumerate(s):
            cnt += 1
            # The end of a substring containing identical chars.
            if i == n-1 or s[i] != s[i+1]:
                if ch == "1":
                    cnt1 += cnt
                else:
                    cnt0_max = max(cnt0_max, prev0 + cnt)
                    prev0 = cnt
                
                cnt = 0
        return cnt1 + cnt0_max