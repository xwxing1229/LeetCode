# https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution:
    def maxValue(self, n, index, maxSum):
        """
        Inputs:
            n, index, maxSum: int
        Outputs:
            res: int
        """
        res = 1
        left, right = 1, maxSum
        while left <= right:
            mid = (right - left) // 2 + left
            n_left = min(mid, index + 1)
            sum_left = (mid + max(mid-index, 1)) * n_left // 2\
                + index + 1 - n_left
            n_right = min(mid, n - index)
            sum_right = (mid + max(mid-n+index+1, 1)) * n_right // 2\
                + n - index - n_right
            if sum_left + sum_right - mid <= maxSum:
                left = mid + 1
                res = mid
            else:
                right = mid - 1
        return res