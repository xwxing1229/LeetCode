# https://leetcode.cn/problems/reconstruct-original-digits-from-english/

class Solution:
    def originalDigits(self, s):
        """
        Inputs:
            s: str
        Outputs:
            res: str
        """
        statistic = dict()
        for ch in s:
            statistic[ch] = statistic.get(ch,0) + 1
        cnt = [0 for i in range(10)]
        cnt[0] = statistic.get("z", 0)
        cnt[2] = statistic.get("w", 0)
        cnt[4] = statistic.get("u", 0)
        cnt[6] = statistic.get("x", 0)
        cnt[8] = statistic.get("g", 0)
        cnt[3] = statistic.get("h", 0) - cnt[8]
        cnt[5] = statistic.get("f", 0) - cnt[4]
        cnt[7] = statistic.get("v", 0) - cnt[5]
        cnt[1] = statistic.get("o", 0) - cnt[0] - cnt[2] - cnt[4]
        cnt[9] = statistic.get("i", 0) - cnt[5] - cnt[6] - cnt[8]
        res = "".join([str(i) * cnt[i] for i in range(10)])
        return res