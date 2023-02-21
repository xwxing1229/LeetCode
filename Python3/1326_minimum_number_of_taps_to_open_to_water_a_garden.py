# https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution:
    def minTaps(self, n, ranges):
        """
        Inputs:
            n: int
            ranges: list[int]
        Outputs:
            res: int
        """
        water = [[0,0] for __ in range(n+1)]
        for i, r in enumerate(ranges):
            water[i][0], water[i][1] = max(0, i-r), min(n, i+r)
        water = sorted(water, key = lambda x: (x[0], -x[1]))

        left, right, right_max = water[0][0], water[0][1], water[0][1]
        if left > 0:
            return -1
        elif right_max == n:
            return 1

        res, i = 1, 1
        while i < n+1:
            while i < n+1 and water[i][0] <= right:
                right_max = max(right_max, water[i][1])
                i += 1

            if i == n:
                break
            
            res += 1
            if right_max == n:
                return res
            elif water[i][0] <= right_max:
                right = right_max
            else:
                return -1
        
        if right_max == n:
            return res + 1
        else:
            return -1