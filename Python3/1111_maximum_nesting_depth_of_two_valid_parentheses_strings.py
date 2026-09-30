# https://leetcode.cn/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        res = [0 for _ in range(len(seq))]
        cnt = [0, 0]
        for i, ch in enumerate(seq):
            if ch == "(":
                if cnt[0] <= cnt[1]:
                    cnt[0] += 1
                else:
                    res[i] = 1
                    cnt[1] += 1
            else:
                if cnt[0] > cnt[1]:
                    cnt[0] -= 1
                else:
                    res[i] = 1
                    cnt[1] -= 1
        return res