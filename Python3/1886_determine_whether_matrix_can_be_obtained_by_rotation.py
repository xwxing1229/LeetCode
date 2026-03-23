# https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution:
    def findRotation(self, mat: list[list[int]], target: list[list[int]]) -> bool:
        def rotateOnce(mat):
            res = [[0 for _ in range(n)] for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    res[j][n-1-i] = mat[i][j]
            return res
        
        def isValid(mat):
            for i in range(n):
                for j in range(n):
                    if mat[i][j] != target[i][j]:
                        return False
            return True
        
        n = len(mat)
        for _ in range(4):
            if isValid(mat):
                return True
            mat = rotateOnce(mat)
        return False