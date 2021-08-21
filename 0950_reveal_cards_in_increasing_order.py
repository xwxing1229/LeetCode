# https://leetcode-cn.com/problems/reveal-cards-in-increasing-order/
class Solution:
    def deckRevealedIncreasing(self, deck):
        """
        Inputs:
            deck: list[int]
        Outputs:
            res: list[int]
        """

        n = len(deck)
        if n == 1:
            return deck

        # Backstepping.
        deck.sort()
        res = [deck[n-2], deck[n-1]]
        for i in range(n-2):
            res = [res[i+1]] + res[0:i+1]
            res = [deck[n-3-i]] + res
        return res