# https://leetcode.cn/problems/find-players-with-zero-or-one-losses/

class Solution:
    def findWinners(self, matches):
        """
        Inputs:
            matches: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        winners, losers = defaultdict(int), defaultdict(int)
        for w, l in matches:
            winners[w] += 1
            losers[l] += 1
        res = [[], []]
        for k, v in winners.items():
            if k not in losers:
                res[0].append(k)
        for k, v in losers.items():
            if v == 1:
                res[1].append(k)
        res[0].sort()
        res[1].sort()
        return res