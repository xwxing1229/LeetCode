# https://leetcode.cn/problems/valid-perfect-square/

class Solution:
    def isPerfectSquare(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: bool
        """

        left = 0
        right = num
        while left <= right:
            mid = left + (right - left) // 2
            sq = mid * mid
            if sq < num:
                left = mid + 1
            elif sq > num:
                right = mid - 1
            else:
                return True
        return False