# https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/

class Solution:
    def maxScore(self, cardPoints, k):
        """
        Inputs:
            cardPoints: list[int]
            k: int
        Outputs:
            res: int
        """
        n = len(cardPoints)
        window, total = 0, 0
        window_len = n-k
        for i in range(window_len):
            window += cardPoints[i]
            total += cardPoints[i]
        window_min = window
        for i in range(window_len, n):
            window += (cardPoints[i] - cardPoints[i-window_len])
            window_min = min(window_min, window)
            total += cardPoints[i]
        return total - window_min