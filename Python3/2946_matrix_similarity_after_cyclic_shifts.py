# https://leetcode.cn/problems/matrix-similarity-after-cyclic-shifts/

class Solution:
    def areSimilar(self, mat: list[list[int]], k: int) -> bool:
        # odd: right, even: left
        m, n = len(mat), len(mat[0])
        k %= n
        flag = 1
        for i, row in enumerate(mat):
            flag *= -1
            for j, val in enumerate(row):
                if row[(j+flag*k+n)%n] != val:
                    return False
        return True