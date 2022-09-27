# https://leetcode.cn/problems/guess-number-higher-or-lower/

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: int
        """
        left = 1
        right = n
        while left <= right:
            mid = left + (right - left) // 2
            guess_result = guess(mid)
            if guess_result == 0:
                return mid
            elif guess_result == 1:
                left = mid + 1
            else:
                right = mid - 1
        return -1