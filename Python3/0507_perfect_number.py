# https://leetcode.cn/problems/perfect-number/

class Solution:
    def checkPerfectNumber(self, num):
        """
        Inputs:
            num: int
        Outputs:
            res: bool
        """
        s = -num
        for i in range(1, int(sqrt(num))+1):
            if num % i == 0:
                s += i
                if i != num // i:
                    s += (num // i)
        if  s == num:
            return True
        else:
            return False