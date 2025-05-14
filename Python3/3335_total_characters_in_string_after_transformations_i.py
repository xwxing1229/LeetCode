
# https://leetcode.cn/problems/total-characters-in-string-after-transformations-i/

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = int(1e9) + 7
        ord_a = ord("a")
        cnt = [0 for _ in range(26)]
        for ch in s:
            cnt[ord(ch) - ord_a] += 1
        for _ in range(t):
            cnt_z = cnt[-1]
            for i in range(25, 1, -1):
                cnt[i] = cnt[i-1]
            cnt[1] = cnt[0] + cnt_z
            cnt[0] = cnt_z
        return sum(cnt) % mod