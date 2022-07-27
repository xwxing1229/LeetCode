# https://leetcode.cn/problems/h-index-ii/

class Solution:
    def hIndex(self, citations):
        """
        Inputs:
            citations: list[int]
        Outputs:
            res: int
        """

        n = len(citations)
        left = 0
        right = n - 1
        res = 0
        while left <= right:
            mid = left + (right - left) // 2
            if n - mid <= citations[mid]:
                right = mid - 1
                res = n - mid
            else:
                left = mid + 1
        return res