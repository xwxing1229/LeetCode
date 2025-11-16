# https://leetcode.cn/problems/number-of-substrings-with-only-1s/

class Solution:
    def numSub(self, s: str) -> int:
        res = 0
        mod = 1000000007
        cnt = 0 # number of valid substrings that end with current 1
        for ch in s:
            if ch == "1":
                cnt += 1
                res = (res + cnt) % mod
            else:
                cnt = 0
        return res