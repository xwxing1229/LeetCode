# https://leetcode.cn/problems/bitwise-and-of-numbers-range/

class Solution:
    def rangeBitwiseAnd(self, left, right):
        """
        Inputs:
            left: int
            right: int
        Outputs:
            res: int
        """

        '''
        # Try to find base1 and base2 such that:
        # 1. base1 >= left,
        # 2. base2 >= base1 and base2 <= right.
        base1 = 1
        while base1 < left:
            base1 = base1 * 2
        base2 = base1
        while base2 * 2 <= right:
            base2 = base2 * 2
        if base1 == base2:
            if base1 >= right:
                res = 0
                base = 1
                for i in range(32):
                    flag = 1
                    for num in range(left, right+1):
                        if ((num >> i) & 1) == 0:
                            flag = 0
                            break
                    res = res + base * flag
                    base = base * 2
                return res

            elif base1 == left:
                return base1
            else:
                return 0
        else:
            return 0
        '''

        # Longest common prefix.
        shift = 0
        while left < right:
            left = left >> 1
            right = right >> 1
            shift = shift + 1
        res = left << shift
        return res