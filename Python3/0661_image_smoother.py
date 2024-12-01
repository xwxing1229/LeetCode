# https://leetcode.cn/problems/image-smoother/

class Solution:
    def imageSmoother(self, img):
        """
        Inputs:
            img: list[list[int]]
        Outputs:
            res: list[list[int]]
        """
        m, n = len(img), len(img[0])
        res = [[0 for _ in range(n)] for _ in range(m)]
        
        dirs = [[[0, 0] for _ in range(3)] for _ in range(3)]
        for i in range(3):
            for j in range(3):
                dirs[i][j][0] += i-1
                dirs[i][j][1] += j-1
        
        for i in range(m):
            for j in range(n):
                s, cnt = 0, 0
                for di in range(3):
                    for dj in range(3):
                        i0, j0 = i+dirs[di][dj][0], j+dirs[di][dj][1]
                        if i0 < 0 or i0 >= m or j0 < 0 or j0 >= n:
                            continue
                        s += img[i0][j0]
                        cnt += 1
                res[i][j] = s // cnt
        return res