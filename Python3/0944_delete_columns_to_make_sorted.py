# https://leetcode.cn/problems/delete-columns-to-make-sorted/

class Solution:
    def minDeletionSize(self, strs: list[str]) -> int:
        res = 0
        n = len(strs)
        for col in range(len(strs[0])):
            for row in range(1, n):
                if strs[row][col] < strs[row-1][col]:
                    res += 1
                    break
        return res