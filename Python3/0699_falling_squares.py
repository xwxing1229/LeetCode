# https://leetcode.cn/problems/falling-squares/

class Solution:
    def fallingSquares(self, positions):
        """
        Inputs:
            positions: list[list[int]]
        Outputs:
            res: list[int]
        """
        n = len(positions)
        heights = [0 for _ in range(n)]
        for i, (left_i, side_i) in enumerate(positions):
            right_i = left_i + side_i
            heights[i] = side_i
            for j in range(i):
                left_j, side_j = positions[j]
                right_j = left_j + side_j
                if right_j > left_i and left_j < right_i:
                    heights[i] = max(heights[i], heights[j]+side_i)

        res = [heights[0] for _ in range(n)]
        for i in range(1, n):
            res[i] = max(res[i-1], heights[i])
        return res