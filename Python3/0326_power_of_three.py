# https://leetcode.cn/problems/power-of-three/

class Solution:
    def isPowerOfThree(self, n):
        """
        Inputs:
            n: int
        Outputs:
            res: bool
        """

        '''
        if n <= 0:
            return False

        rem = n % 3
        while rem == 0:
            n = n // 3
            rem = n % 3
        if n == 1:
            return True
        else:
            return False
        '''

        # Check if n is a divisor of 3^19 which is the largest
        # integer in [-2^31, 2^31-1].
        if (n > 0) and (1162261467 % n == 0):
            return true
        else:
            return false