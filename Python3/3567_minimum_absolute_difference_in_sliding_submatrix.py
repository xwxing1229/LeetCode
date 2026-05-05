# https://leetcode.cn/problems/minimum-absolute-difference-in-sliding-submatrix/

from collections import defaultdict

class Solution:
    def minAbsDiff(self, grid: list[list[int]], k: int) -> list[list[int]]:
                
        def addCol(tl_row, col):
            nonlocal cnt
            for i in range(tl_row, tl_row+k):
                cnt[grid[i][col]] += 1
        
        def removeCol(tl_row, col):
            nonlocal cnt
            for i in range(tl_row, tl_row+k):
                num = grid[i][col]
                cnt[num] -= 1
                if cnt[num] == 0:
                    cnt.pop(num)
        
        def reset(tl_row, tl_col):
            nonlocal cnt
            cnt.clear()
            for j in range(tl_col, tl_col+k-1):
                addCol(tl_row, j)

        def subMinAbsDiff():
            nums = sorted(cnt.keys())
            res = 0
            for i in range(len(nums)-1):
                tmp = nums[i+1] - nums[i]
                if res == 0 or res > tmp:
                    res = tmp
            return res

        m, n = len(grid), len(grid[0])
        res = [[0 for _ in range(n-k+1)] for _ in range(m-k+1)]
        cnt = defaultdict(int)
        for i in range(m-k+1):
            reset(i, 0)
            for j in range(n-k+1):
                addCol(i, j+k-1)
                res[i][j] = subMinAbsDiff()
                removeCol(i, j)
        return res