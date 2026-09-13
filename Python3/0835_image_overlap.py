# https://leetcode.cn/problems/image-overlap/

class Solution:
    def largestOverlap(self, img1: list[list[int]], img2: list[list[int]]) -> int:
        n = len(img1)
        res = 0
        for x in range(1-n, n):
            for y in range(1-n, n):
                tmp = 0
                for i in range(max(-x, 0), min(n-x, n)):
                    for j in range(max(-y, 0), min(n-y, n)):
                        tmp += img1[i][j] * img2[i+x][j+y]
                res = max(res, tmp)
        return res