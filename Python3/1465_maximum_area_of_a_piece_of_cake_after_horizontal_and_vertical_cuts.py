# https://leetcode.cn/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution:
    def maxArea(self, h, w, horizontalCuts, verticalCuts):
        """
        Inputs:
            h, w: int
            horizontalCuts, verticalCuts: list[int]
        Outputs:
            res: int
        """
        mod = 1000000007
        horizontalCuts.sort()
        verticalCuts.sort()
        h_max, v_max = horizontalCuts[0], verticalCuts[0]
        for i in range(1, len(horizontalCuts)):
            h_max = max(h_max, horizontalCuts[i] - horizontalCuts[i-1])
        h_max = max(h_max, h - horizontalCuts[-1])
        for i in range(1, len(verticalCuts)):
            v_max = max(v_max, verticalCuts[i] - verticalCuts[i-1])
        v_max = max(v_max, w - verticalCuts[-1])
        return h_max * v_max % mod