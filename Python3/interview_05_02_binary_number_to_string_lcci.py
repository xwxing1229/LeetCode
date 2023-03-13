# https://leetcode.cn/problems/bianry-number-to-string-lcci/

class Solution:
    def printBin(self, num):
        """
        Inputs:
            num: float
        Outputs:
            res: str
        """
        num_new = 2 ** 6 * num
        num_int = int(math.ceil(num_new))
        if num_int != int(math.floor(num_new)):
            return "ERROR"

        res = ""
        digits = 0
        while num_int % 2 == 0:
            print(num_int)
            num_int //= 2
            digits += 1
        while num_int > 0:
            res = str(num_int % 2) + res
            num_int //= 2
            digits += 1
        res = "0." + "0" * (6 - digits) + res
        return res