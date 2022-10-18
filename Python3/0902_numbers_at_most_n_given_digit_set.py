# https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/

class Solution:
    def atMostNGivenDigitSet(self, digits, n):
        """
        Inputs:
            digits: list[str]
            n: int
        Outputs:
            res: int
        """
        s = str(n)
        n_d, n_n = len(digits), len(s)
        res = 0
        power = 1
        powers = [1]
        # Count number of numbers whose sizes are less than n_n.
        for i in range(n_n-1):
            power *= n_d
            res += power
            powers.append(power)
        # Count number of numbers whose sizes are equal to n_n and that
        # are less than n.
        for i in range(n_n):
            same = False
            for ch in digits:
                if s[i] > ch:
                    res += powers[n_n-1-i]
                elif s[i] == ch:
                    same = True
                    break
                else:
                    break
            
            if not same:
                return res
        
        return res + 1