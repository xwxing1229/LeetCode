# https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution:
    def numPairsDivisibleBy60(self, time):
        """
        Inputs:
            time: list[int]
        Outputs:
            res: int
        """
        cnt = [0 for _ in range(60)]
        for t in time:
            cnt[t%60] += 1
        res = cnt[0] * (cnt[0] - 1) / 2
        for i in range(1, 30):
            res += cnt[i] * cnt[60-i]
        res += (cnt[30] * (cnt[30] - 1) / 2)
        return res