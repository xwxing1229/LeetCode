# https://leetcode.cn/problems/alternating-groups-i/

class Solution:
    def numberOfAlternatingGroups(self, colors):
        """
        Inputs:
            colors: list[int]
        Outputs:
            res: int
        """
        res = 0
        for i in range(len(colors)-1):
            if colors[i] != colors[i-1] and colors[i] != colors[i+1]:
                res += 1
        if colors[-1] != colors[-2] and colors[-1] != colors[0]:
            res += 1
        return res