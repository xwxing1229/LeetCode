# https://leetcode.cn/problems/maximum-length-substring-with-two-occurrences/

class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        res = 0
        cnt = [0 for _ in range(26)]
        left = 0
        for i, ch in enumerate(s):
            idx = ord(ch) - ord("a")
            cnt[idx] += 1
            while cnt[idx] > 2:
                cnt[ord(s[left]) - ord("a")] -= 1
                left += 1
            res = max(res, i - left + 1)
        return res