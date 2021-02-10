# https://leetcode-cn.com/problems/container-with-most-water/

class Solution:
    def maxArea(self, height):
        """
        Inputs:
            height: list[int]
        Outputs:
            res: int
        """

        res = 0
        left = 0
        right = len(height) - 1

        while left < right:
            hleft = height[left]
            hright = height[right]

            tmp = min(hleft, hright) * (right - left)
            res = max(res, tmp)

            if hleft < hright:
                left = left + 1
            else:
                right = right - 1

        return res