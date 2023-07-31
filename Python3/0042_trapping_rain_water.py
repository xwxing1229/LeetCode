# https://leetcode.cn/problems/trapping-rain-water/

class Solution:
    def trap(self, height):
        """
        Inputs:
            height: list[int]
        Outputs:
            res: int
        """
        n = len(height)
        max_left = [0 for _ in range(n)]
        max_right = [0 for _ in range(n)]
        for i in range(1, n):
            max_left[i] = max(max_left[i-1], height[i-1])
        for i in range(n-2, -1, -1):
            max_right[i] = max(max_right[i+1], height[i+1])
        res = 0
        for i in range(1, n-1):
            h = min(max_left[i], max_right[i])
            if h > height[i]:
                res += h - height[i]
        return res