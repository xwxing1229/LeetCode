# https://leetcode.cn/problems/count-the-number-of-substrings-with-dominant-ones/

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        res = 0
        pos0 = [-1]
        cnt1 = 0 # number of 1 in [0, right]
        for right, ch in enumerate(s):
            if ch == "0":
                pos0.append(right)
            else:
                cnt1 += 1
                res += right - pos0[-1] # substring s[~, right] that only includes 1
            
            n = len(pos0)
            for i in range(n-1, 0, -1):
                cnt0 = n - i # number of 0 in [pos0[i], right]
                cnt0_sq = cnt0 * cnt0
                if cnt0_sq > cnt1:
                    break
                pre, cur = pos0[i-1], pos0[i]
                cnt1_sub = right - cur + 1 - cnt0 # number of 1 in [pos0[i], right]

                if cnt0_sq <= cnt1_sub:
                    valid = cur - pre
                else:
                    valid = max(cur - pre - (cnt0_sq - cnt1_sub), 0)
                res += valid

        return res