# https://leetcode.cn/problems/find-indices-of-stable-mountains/

class Solution:
    def stableMountains(self, height, threshold):
        """
        Inputs:
            height: list[int]
            threshold: int
        Outputs:
            res: list[int]
        """
        res = []
        for i in range(1, len(height)):
            if height[i-1] > threshold:
                res.append(i)
        return res