# https://leetcode.cn/problems/time-needed-to-buy-tickets/

class Solution:
    def timeRequiredToBuy(self, tickets, k):
        """
        Inputs:
            tickets: list[int]
            k: int
        Outputs:
            res: int
        """
        res, val = tickets[k], tickets[k]
        for i in range(k):
            res += min(tickets[i], val)
        for i in range(k+1, len(tickets)):
            res += min(tickets[i], val-1)
        return res