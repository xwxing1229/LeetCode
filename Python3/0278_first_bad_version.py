# https://leetcode.cn/problems/first-bad-version/

# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """

        left = 1
        right = n
        res = n
        while left <= right:
            mid = left + (right - left) // 2
            if isBadVersion(mid):
                right = mid - 1
                res = mid
            else:
                left = mid + 1
        return left