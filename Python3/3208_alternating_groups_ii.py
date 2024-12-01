# https://leetcode.cn/problems/alternating-groups-ii/

class Solution:
    def numberOfAlternatingGroups(self, colors, k):
        """
        Inputs:
            colors: list[int]
            k: int
        Outputs:
            res: int
        """
        colors = colors + colors[: k-1]
        res, cnt = 0, 1
        for i in range(len(colors)-1):
            if colors[i] != colors[i+1]:
                cnt += 1
            else:
                cnt = 1
            
            if cnt >= k:
                res += 1
        
        return res