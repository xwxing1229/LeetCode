# https://leetcode.cn/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        res = n
        # cnt0: number of chars that match "010101...".
        # cnt1: number of chars that match "101010...".
        cnt0, cnt1 = 0, 0
        for i in range(2*n-1):
            ch = s[i % n]
            if int(ch) == min(i, n-1) % 2:
                cnt0 += 1
            else:
                cnt1 += 1
            if i >= n-1:
                res = min(res, min(cnt0, cnt1))
                if int(s[i-(n-1)]) == 0:
                    cnt0 -= 1
                else:
                    cnt1 -= 1
                cnt0, cnt1 = cnt1, cnt0
        return res