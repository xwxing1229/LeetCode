# https://leetcode.cn/problems/count-substrings-that-satisfy-k-constraint-i/

class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        res = 0
        i = 0
        cnt = [0, 0]
        for j, ch in enumerate(s):
            cnt[int(ch)] += 1
            while cnt[0] > k and cnt[1] > k and i <= j:
                cnt[int(s[i])] -= 1
                i += 1
            res += j - i + 1
        return res